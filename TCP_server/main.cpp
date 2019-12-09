#include <iostream>
#include "Server.h"
#include "reliable_portocols/Stop_wait.h"
#include "reliable_portocols/Selective_repeat.h"

int main() {
    string line;
    ifstream myfile ("test.txt");
    int port;
    int seed;
    float prop;
    if (myfile.is_open())
    {
        myfile >> port;
        myfile >> seed;
        myfile >> prop;
        myfile.close();
    }
    Server* main = new Server();
    main->bind(to_string(port));
    //freopen ("output.txt","w",stdout);
    int c = 1;
    while(1){
        struct sockaddr_in *client = (struct sockaddr_in*) malloc(sizeof(struct sockaddr_in));
        string file_name = main->request_handler(client,port+c);
        //int new_port = port + c;

        //main->send_new_port(new_port);
        if(fork() == 0){
            Reliable_abstract* rdt = new Selective_repeat(prop,seed);
            Server* sr = new Server();
            sr->bind(to_string(port+c));
            sr->start(rdt);
            exit(0);
        }
        c++;
    }

    return 0;
}