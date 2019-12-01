//
// Created by muhammed on 11/24/19.
//


#include "Selective_repeat.h"


void Selective_repeat::send_file(int sock_fd, struct addrinfo *address, string fileName) {
    this->sock_fd = sock_fd;
    this->addr = address;
    this->fileName = fileName;
    read_packet();

    pthread_t transmitter;
    pthread_t acker;
    pthread_t monitor;
    pthread_create(&transmitter,NULL,data_transimmiter,this);
    pthread_create(&acker,NULL,ack_receiver,this);
    pthread_create(&monitor,NULL,time_monitor,this);
    pthread_join(transmitter,NULL);
    pthread_join(acker,NULL);
    pthread_join(monitor,NULL);
}



void Selective_repeat::read_packet() {
    ifstream in_file;
    in_file.open(this->fileName, ios::binary | std::ios::in);
    in_file.seekg(0, std::ios::end);
    int file_size = in_file.tellg();
    this->file_size =file_size;
    data.resize(file_size);
    in_file.seekg(0, ios::beg);
    in_file.read(&data[0],file_size);
    number_of_packets = file_size/500;
    if(file_size%500 != 0){
        number_of_packets++;
    }
    in_file.close();
    packets.resize(number_of_packets);

    sr_packet *sr;
    data_packet *pk;
    for(int i = 0;i < number_of_packets;i++){
        sr = new sr_packet;
        pk = new data_packet;
        strncpy(pk->data,&data[0]+i*500,500);
        pk->len = sizeof(data_packet);
        pk->seqno = 0;

        sr->pk = pk;
        packets[i] = sr;
    }
}


void* data_transimmiter(void *arg){
    Selective_repeat *sr = (Selective_repeat*) arg;
    while(sr->base < sr->number_of_packets){
        sr->mtx.lock();
        for (int i = 0; i < sr->cwnd; ++i) {
            if(sr->transmitted.find(i+sr->base) == sr->transmitted.end()){
                ((Reliable_abstract* )sr)->sendUDP(sr->sock_fd,sr->addr,sr->packets[i+sr->base]->pk,
                        sr->packets[i+sr->base]->pk->len);
                sr->packets[i+sr->base]->t = clock();
                sr->transmitted.insert(i+sr->base);
            }
        }
        sr->mtx.unlock();
    }
    fin_packet f;
    ((Reliable_abstract* )sr)->sendUDP(sr->sock_fd,sr->addr,&f,1);
}


void* ack_receiver(void* arg){
    Selective_repeat *sr = (Selective_repeat*) arg;
    while(true){
        ack_packet pk;
        bool rv = ((Reliable_abstract* )sr)->rcvUDP(sr->sock_fd,&pk,sr->addr, true,10,true);
        if(!rv) break;
        if(pk.len == 0) break;
        sr->mtx.lock();
        if(sr->transmitted.find(pk.ackno) != sr->transmitted.end()){
            sr->packets[pk.ackno]->acked = true;
            while(sr->packets[sr->base]->acked) {
                sr->transmitted.erase(sr->base);
                sr->base++;
            }
        }
        sr->mtx.unlock();
    }
    sr->kill_timers = true;
}

void* time_monitor(void* arg){
    Selective_repeat *sr = (Selective_repeat*) arg;
    while(!sr->kill_timers){
        for(auto ele : sr->transmitted){
            if(!sr->packets[ele]->acked){
                int time = (clock() - sr->packets[ele]->t) / CLOCKS_PER_SEC;
                if(time > 5){
                    ((Reliable_abstract* )sr)->sendUDP(sr->sock_fd,sr->addr,sr->packets[ele]->pk,
                                                       sr->packets[ele]->pk->len);
                    sr->packets[ele]->t = clock();
                }
            }
        }
    }
}


void Selective_repeat::recv_file(int sock_fd, struct addrinfo *address, string fileName) {
    fp = fopen(fileName.c_str(),"wb");
    data_packet *pk;
    this->addr = address;
    while(true){
        pk = new data_packet;
        memset(pk,0,sizeof(data_packet));
        bool rv = rcvUDP(sock_fd,pk,addr, true,20, false);
        printf("base: %d\n",base);
        if(!rv){
            ack_packet *ack = new ack_packet;
            ack->len = 0;
            sendUDP(sock_fd,addr,ack,sizeof(ack_packet));
            break;
        }
        if(pk->seqno >= base && pk->seqno < base + cwnd){
            if(buffered_data.find(pk->seqno) == buffered_data.end()){
                string str = pk->data;
                buffered_data[pk->seqno] = str;
            }
            ack_packet *p = new ack_packet;
            p->ackno = pk->seqno;
            p->rcv_window = cwnd;
            p->len = sizeof(ack_packet);
            sendUDP(sock_fd,addr,p,p->len);
            if(pk->seqno == base){
                while(buffered_data.find(base) != buffered_data.end()){
                    fwrite(buffered_data[base].c_str(),sizeof(char),buffered_data[base].size(),fp);
                    buffered_data.erase(base);
                    base++;
                }
            }
        }else if(pk->seqno < base){
            ack_packet *p = new ack_packet;
            p->ackno = pk->seqno;
            p->len = sizeof(ack_packet);
            p->rcv_window = cwnd;
            sendUDP(sock_fd,addr,p,p->len);
        }

    }
    while(buffered_data.find(base) != buffered_data.end()){
        fwrite(buffered_data[base].c_str(),sizeof(char),buffered_data[base].size(),fp);
        buffered_data.erase(base);
        base++;
    }
    fclose(fp);
}