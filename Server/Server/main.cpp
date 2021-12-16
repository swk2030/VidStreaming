#include "Network.h"
#include "Server.h"
#include "Client.h"
#include "Streamer.h"
int main() {
    Server serv("11000");
    serv.establish_network();
    serv.cleanNetwork();

    Streamer stream(&serv);
    stream.sendData("test.mp4");

    return 0;
}