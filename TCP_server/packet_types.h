//
// Created by muhammed on 11/23/19.
//

#ifndef TCP_CLIENT_PACKET_TYPES_H
#define TCP_CLIENT_PACKET_TYPES_H

#include <cstdint>

struct data_packet{
    /* Header */
    uint16_t cksum;
    uint16_t len = 0;
    uint32_t seqno;
    /* Data */
    char data[500];
};

struct ack_packet{
    /* Header */
    uint16_t cksum;
    uint16_t len;
    uint32_t ackno;
    uint16_t rcv_window;
};

struct fin_packet{
    char f = 'f';
};


#endif //TCP_CLIENT_PACKET_TYPES_H
