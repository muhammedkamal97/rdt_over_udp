#include <iostream>
#include "Server.h"
#include "reliable_portocols/Stop_wait.h"
#include "reliable_portocols/Selective_repeat.h"

int main() {
    Server* sr = new Server();
    sr->bind("8080");
    Reliable_abstract* rdt = new Selective_repeat(0.05);
    sr->start(rdt);
    return 0;
}