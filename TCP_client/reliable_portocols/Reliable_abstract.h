//
// Created by muhammed on 11/23/19.
//

#ifndef TCP_CLIENT_RELIABLE_ABSTRACT_H
#define TCP_CLIENT_RELIABLE_ABSTRACT_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "../packet_types.h"


using namespace std;

class Reliable_abstract {
public:
    Reliable_abstract(float propability,int seed);
    virtual void recv_file(int sock_fd,struct addrinfo* address,string fileName) = 0;
    virtual void send_file(int sock_fd,struct addrinfo* address,string fileName) = 0;
    void sendUDP(int sock_fd,struct addrinfo* address, void* buffer,int len);
    bool rcvUDP(int sock_fd,void *packet,struct addrinfo* address, bool block,int time_out,bool is_ack);
    string file_name;

private:
    float propability;
    bool propability_loss();
};


#endif //TCP_CLIENT_RELIABLE_ABSTRACT_H
