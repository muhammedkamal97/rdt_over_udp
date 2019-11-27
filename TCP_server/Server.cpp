//
// Created by muhammed on 11/23/19.
//

#include "Server.h"

void Server::bind(string port) {
    struct addrinfo hints, *res;

    memset(&hints,0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // set to AF_INET to force IPv4
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE; // use my IP
    int rv;
    if ((rv = getaddrinfo(NULL, port.c_str(), &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(-1);
    }
    this->sock_fd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);

    if(this->sock_fd == -1){
        printf("create socket failed\n");
        exit(1);
    }
    if (::bind(sock_fd, res->ai_addr, res->ai_addrlen) == -1) {
        close(sock_fd);
        perror("listener: bind");
        exit(-1);
    }
    printf("bind success\n");
    this->server = res;
}

void Server::start(Reliable_abstract* rdt) {
    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    size_t n;
    socklen_t len = sizeof(struct sockaddr_in);
    n = recvfrom(sock_fd, (char *) buffer, 1024,0, (struct sockaddr *) &client, &len);

    string file_name = string(buffer,buffer+n);
    printf("requested file name: %s\n",file_name.c_str());

    struct addrinfo hints, *res;

    this->client.ai_addr = ((struct sockaddr*)&client);
    this->client.ai_addrlen = sizeof(this->client);
    this->client.ai_family = AF_UNSPEC;
    this->client.ai_socktype = SOCK_DGRAM;
    this->client.ai_protocol = 0;



    rdt->send_file(sock_fd,&this->client,file_name);
}