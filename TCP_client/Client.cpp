//
// Created by muhammed on 11/23/19.
//





#include "Client.h"


Client::Client(string arg_file) {
    ifstream f(arg_file);
    if(f.good()){
        f >> this->server_ip;
        f >> this->server_port;
        f >> this->file_name;
    }else{
        cout << file_name << " not found\n";
        exit(-1);
    }
}

void Client::connect() {
    struct addrinfo *result;
    struct addrinfo hints;
    memset(&hints,0,sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if(getaddrinfo((this->server_ip).c_str(),
            (this->server_port).c_str(),&hints,&result) != 0){
        printf("error in get address info\n");
        exit(-1);
    }
    this->server = result;
    this->sock_fd = socket(result->ai_family,result->ai_socktype,result->ai_protocol);
    if(this->sock_fd == -1){
        printf("error in socket\n");
    }
}

void Client::receive_file(Reliable_abstract *rdt) {
    //create data packet
    int st = sendto(this->sock_fd,this->file_name.c_str(),this->file_name.size(),
            0,this->server->ai_addr,this->server->ai_addrlen);
    if(st == -1){
        printf("error in send to\n");
        exit(-1);
    }
    //the receiver way of communication handle
    rdt->recv_file(this->sock_fd,this->server,this->file_name);
}