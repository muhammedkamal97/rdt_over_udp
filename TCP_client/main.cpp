#include <iostream>
#include "Client.h"
#include "reliable_portocols/Stop_wait.h"
#include "reliable_portocols/Selective_repeat.h"
#include <chrono>
using namespace std::chrono;


int main() {
    Client* cl = new Client("test.txt");
    cl->connect();
    Reliable_abstract* rdt = new Selective_repeat(0.3,10);
    ((Selective_repeat*) rdt)->cwnd = 10000;
    auto start = high_resolution_clock::now();
    cl->receive_file(rdt);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count()*1000 <<endl;
    return 0;
}