#include "Network.h"
#include "Server.h"
#include "Client.h"
#include "Streamer.h"
#include <time.h>
int main() {
    Server serv("11000");
    serv.establish_network();

    Streamer stream(serv.getClientSock(), serv.getClientAddr());
    
    while (1) {
        stream.recvRequest();
    }


    serv.cleanNetwork();

    return 0;
}       