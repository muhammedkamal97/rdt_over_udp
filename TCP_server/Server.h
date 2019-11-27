//
// Created by muhammed on 11/23/19.
//

#ifndef TCP_SERVER_SERVER_H
#define TCP_SERVER_SERVER_H

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
#include "reliable_portocols/Reliable_abstract.h"

using namespace std;

class Server {
public:
    void bind(string port);
    void start(Reliable_abstract* rdt);

private:
    int sock_fd;
    struct addrinfo* server;
    struct addrinfo client;

};


#endif //TCP_SERVER_SERVER_H
