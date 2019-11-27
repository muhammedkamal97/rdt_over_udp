//
// Created by muhammed on 11/23/19.
//

#include "Reliable_abstract.h"

Reliable_abstract::Reliable_abstract(float propability) {
    this->propability = propability;
}


bool Reliable_abstract::propability_loss() {
    srand(time(0));
    int random_num = (rand()%100)+1;
    if(random_num <= this->propability*100){
        return true;
    }else{
        return false;
    }
}

void Reliable_abstract::sendUDP(int sock_fd, struct addrinfo* address, void *buffer, int len) {
    if(!propability_loss()){
        sendto(sock_fd, buffer,sizeof(data_packet),MSG_CONFIRM,address->ai_addr,address->ai_addrlen);
        printf("send packet %d\n",((data_packet*)buffer)->seqno);

    }else{
        printf("packet %d is lost\n",((data_packet*)buffer)->seqno);
    }
}

bool Reliable_abstract::rcvUDP(int sock_fd, void *packet,struct addrinfo* address, bool block,int time_out,bool is_ack) {
    if(block){
        struct timeval timeout;
        timeout.tv_sec = time_out;
        timeout.tv_usec = 0;
        setsockopt(sock_fd,SOL_SOCKET,SO_RCVTIMEO,(const char*)&timeout,sizeof(timeout));
    }

    if(is_ack){
        memset(packet, 0, sizeof packet);
        char a[1];
        int ts = recvfrom(sock_fd,a,1,MSG_PEEK,address->ai_addr,&(address->ai_addrlen));
        if(a[0] == 'f'){
            return false;
        }

        int rv = recvfrom(sock_fd,packet,sizeof(ack_packet),MSG_WAITALL,address->ai_addr,&(address->ai_addrlen));
        if(rv <= 0){
            return false;
        }
        printf("received ack %d\n",((ack_packet*)packet)->ackno);
    } else{
        memset(packet, 0 ,sizeof packet);
        int rv = recvfrom(sock_fd,packet,sizeof(data_packet),MSG_WAITALL,address->ai_addr,&(address->ai_addrlen));
        if(rv <= 1){
            return false;
        }
        printf("received packet %d\n",(((data_packet*)packet)->seqno));
    }
    return  true;
}