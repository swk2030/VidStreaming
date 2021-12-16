#pragma once
#include "Network.h"
#include "Server.h"

class Streamer {
private:
    SOCKET* cli_sock;
    struct sockaddr_in* serv_addr;
    uint8_t* stream_buffer;
    long long szData;
    long long size;
public:
    Streamer(SOCKET*, struct sockaddr_in*);
    void recvData() {};
    void sendData(std::string filename);    //single input
    void sendData(std::string* filenames) {};  //multiple input

    long long size() { return size; }
};