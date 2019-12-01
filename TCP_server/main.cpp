#include <iostream>
#include "Server.h"
#include "reliable_portocols/Stop_wait.h"
#include "reliable_portocols/Selective_repeat.h"

int main() {
    string line;
    ifstream myfile ("test.txt");
    string port;
    int seed;
    float prop;
    if (myfile.is_open())
    {
        myfile >> port;
        myfile >> seed;
        myfile >> prop;
        myfile.close();
    }
    Server* sr = new Server();
    sr->bind(port);
    freopen ("output.txt","w",stdout);
    Reliable_abstract* rdt = new Selective_repeat(prop,seed);
    sr->start(rdt);
    return 0;
}