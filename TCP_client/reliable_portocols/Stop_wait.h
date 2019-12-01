//
// Created by muhammed on 11/23/19.
//

#ifndef TCP_CLIENT_STOP_WAIT_H
#define TCP_CLIENT_STOP_WAIT_H


#include "Reliable_abstract.h"

class Stop_wait: public Reliable_abstract {
public:
    Stop_wait(float propapility,int seed): Reliable_abstract(propapility,seed){};
    void recv_file(int sock_fd,struct addrinfo* address,string fileName) override;
    void send_file(int sock_fd,struct addrinfo* address,string fileName) override;
};


#endif //TCP_CLIENT_STOP_WAIT_H
