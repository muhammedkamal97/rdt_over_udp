//
// Created by muhammed on 11/25/19.
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
    printf("sending %d packet\n",number_of_packets);
    in_file.close();
    packets.resize(number_of_packets);
    sr_packet *sr;
    data_packet *pk;
    for(int i = 0;i < number_of_packets;i++){
        sr = new sr_packet;
        pk = new data_packet;
        strncpy(pk->data,&data[0]+i*500,500);
        pk->len = sizeof(data_packet);
        pk->seqno = i;

        sr->pk = pk;
        packets[i] = sr;
    }

}


void* data_transimmiter(void *arg){
    Selective_repeat *sr = (Selective_repeat*) arg;
    while(sr->base < sr->number_of_packets){
        sr->mtx.lock();
        for (int i = 0; i < sr->cwnd; ++i) {
            if(i+(sr->base) < sr->number_of_packets
                    && sr->transmitted.find(i+(sr->base)) == sr->transmitted.end()){
                ((Reliable_abstract* )sr)->sendUDP(sr->sock_fd,sr->addr,sr->packets[i+(sr->base)]->pk,
                                                   sr->packets[i+(sr->base)]->pk->len);
                sr->packets[i+sr->base]->t = clock();
                sr->transmitted.insert(i+(sr->base));
                printf("cwnd : %d\n", sr->cwnd);
            }
        }

        sr->mtx.unlock();
    }

    fin_packet f;
    sendto(sr->sock_fd,&f,1,MSG_CONFIRM,sr->addr->ai_addr,sr->addr->ai_addrlen);
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
            while(sr->base < sr->number_of_packets && sr->packets[sr->base]->acked) {
                sr->transmitted.erase(sr->base);
                sr->base++;
            }
            sr->update_ack(pk.rcv_window);
            //printf("rcv_window : %d\n", pk.rcv_window);
            //printf("cwnd : %d\n", sr->cwnd);
        }
        sr->mtx.unlock();
    }
    sr->kill_timers = true;
}

void Selective_repeat::update_ack(int rcv_window) {
    if(slow_start){
        cwnd = min(cwnd*2,rcv_window);
        cwnd = max(1,cwnd);
        if(cwnd >= threashold){
            slow_start = false;
            congestion_avoidance = true;
        }
    }else if(congestion_avoidance){
        cwnd = min(cwnd+1,rcv_window);
        cwnd = max(1,cwnd);
    }
}

void Selective_repeat::update_timeout() {
    threashold = max(1,cwnd/2);
    cwnd = max(1,cwnd/2);
    slow_start = true;
}

void* time_monitor(void* arg){
    Selective_repeat *sr = (Selective_repeat*) arg;
    while(!sr->kill_timers){
        for(auto ele : sr->transmitted){
            sr->mtx.lock();
            if(!sr->packets[ele]->acked){
                int time = (clock() - sr->packets[ele]->t);
                if(time > 2000){
                    ((Reliable_abstract* )sr)->sendUDP(sr->sock_fd,sr->addr,sr->packets[ele]->pk,
                                                       sr->packets[ele]->pk->len);
                    sr->packets[ele]->t = clock();
                    sr->update_timeout();
                    //printf("timeout : %d\n", sr->packets[ele]->pk->seqno);
                    //printf("cwnd : %d\n", sr->cwnd);
                }
            }
            sr->mtx.unlock();
        }
    }
}


void Selective_repeat::recv_file(int sock_fd, struct addrinfo *address, string fileName) {
    fp = fopen(fileName.c_str(),"wb");
    while(true){
        data_packet pk;
        bool rv = rcvUDP(sock_fd,&pk,addr, true,4, false);
        if(!rv){
            ack_packet ack;
            ack.len = 0;
            sendUDP(sock_fd,addr,&pk,sizeof(ack_packet));
            break;
        }
        if(pk.seqno >= base && pk.seqno < base+cwnd){
            if(buffered_data.find(pk.seqno) == buffered_data.end()){
                string str = pk.data;
                buffered_data[pk.seqno] = str;
            }
            ack_packet p;
            p.ackno = pk.seqno;
            p.len = sizeof(ack_packet);
            sendUDP(sock_fd,addr,&p,p.len);
            if(pk.seqno == base){
                while(buffered_data.find(base) == buffered_data.end()){
                    fwrite(buffered_data[base].c_str(),sizeof(char),buffered_data[base].size(),fp);
                    buffered_data.erase(base);
                    base++;
                }
            }
        }
    }
    while(buffered_data.find(base) == buffered_data.end()){
        fwrite(buffered_data[base].c_str(),sizeof(char),buffered_data[base].size(),fp);
        buffered_data.erase(base);
        base++;
    }
}