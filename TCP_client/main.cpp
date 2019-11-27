#include <iostream>
#include "Client.h"
#include "reliable_portocols/Stop_wait.h"
#include "reliable_portocols/Selective_repeat.h"

int main() {
    Client* cl = new Client("test.txt");
    cl->connect();
    Reliable_abstract* rdt = new Selective_repeat(0.05);
    cl->receive_file(rdt);
    return 0;
}