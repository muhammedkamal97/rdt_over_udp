//
// Created by muhammed on 11/23/19.
//

#ifndef TCP_CLIENT_CLIENT_H
#define TCP_CLIENT_CLIENT_H

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

class Client {
public:
    Client(string arg_file);
    void connect();
    void receive_file(Reliable_abstract *rdt);

private:
    string server_ip;
    string server_port;
    string file_name;
    int sock_fd;
    struct addrinfo *server;
};


#endif //TCP_CLIENT_CLIENT_H
