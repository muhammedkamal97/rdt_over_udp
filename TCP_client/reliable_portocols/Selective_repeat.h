//
// Created by muhammed on 11/24/19.
//

#ifndef TCP_CLIENT_SELECTIVE_REPEAT_H
#define TCP_CLIENT_SELECTIVE_REPEAT_H


#include <vector>
#include <map>
#include <mutex>
#include <pthread.h>
#include <set>
#include "Reliable_abstract.h"

struct wrapper{
    void* ptr;
};

struct sr_packet{
    data_packet* pk;
    bool acked = false;
    time_t t = -1;
};

class Selective_repeat: public Reliable_abstract {
public:
    Selective_repeat(float propapility,int seed): Reliable_abstract(propapility,seed){};
    void recv_file(int sock_fd,struct addrinfo* address,string fileName) override;
    void send_file(int sock_fd,struct addrinfo* address,string fileName) override;

    FILE *fp;

    int number_of_packets;
    int data_index = 0;
    int file_size;
    vector<sr_packet*> packets;
    void read_packet();
    int cwnd = 50;
    int sock_fd;
    struct addrinfo *addr;
    string fileName;
    vector<char> data;

    //transmitter
    vector<time_t> timers;
    set<int> transmitted;
    int base = 0;
    mutex mtx;
    bool kill_timers = false;

    //receiver
    vector<ack_packet> received;
    map<int,string> buffered_data;


};
void* data_transimmiter(void* arg);
void* ack_receiver(void* arg);
void* time_monitor(void* arg);


#endif //TCP_CLIENT_SELECTIVE_REPEAT_H
