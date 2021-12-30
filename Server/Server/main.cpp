#include "Network.h"
#include "Server.h"
#include "Client.h"
#include "Streamer.h"
#include <time.h>
int main() {
    Server serv("11000");
    serv.establish_network();

    Streamer stream(serv.getClientSock(), serv.getClientAddr());
    std::string filenames[] = { "1.mp4", "2.mp4", "3.mp4", "4.mp4", "5.mp4" };
    for (int i = 0; i < 5; i++) {
        stream.sendData(filenames[i]);
        Sleep(2000);
    }
    serv.cleanNetwork();

    return 0;
}       