//
// Created by muhammed on 11/23/19.
//


#include "Stop_wait.h"



void Stop_wait::recv_file(int sock_fd,struct addrinfo* address,string fileName) {
    FILE *fp = fopen(fileName.c_str(),"wb");
    data_packet packet;
    int seq = 1;
    bool rv;
    do{
        memset(&packet,0,sizeof(data_packet));
        rv = rcvUDP(sock_fd,&packet,address,true,30, false);
        if(packet.seqno = seq && rv){
            string data = packet.data;
            fwrite(data.c_str(),sizeof(char),data.size(),fp);
            ack_packet ack;
            ack.ackno = seq;
            seq++;
            ack.len = sizeof(ack_packet);
            sendUDP(sock_fd,address,&ack,ack.len);
        }
    }while(rv);


}

void Stop_wait::send_file(int sock_fd,struct addrinfo* address,string fileName) {
    uint32_t seq = 1;
    char buffer[500];
    memset(buffer,0,500);
    FILE *fp = fopen(fileName.c_str(),"rb");
    uint16_t read = 0;
    while(read = fread(buffer,1,500,fp) > 0){
        data_packet packet;
        packet.len = read;
        packet.seqno = seq;
        strcpy(packet.data,buffer);
        bool rv;
        do{
            sendUDP(sock_fd,address,(void*)&packet,sizeof(data_packet));
            ack_packet ack_pk;
            rv = rcvUDP(sock_fd,&ack_pk,address,true,30,true);
        }while(!rv);

        if(seq == packet.seqno) seq++;


    }
}