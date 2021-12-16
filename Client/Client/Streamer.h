#pragma once
#include "Network.h"
#include "Client.h"

class Streamer {
private:
    SOCKET* sock;
    struct sockaddr_in* serv_addr;
    uint8_t* stream_buffer;
    long long szData;
    long long size;
public:
    Streamer(Network*);
    ~Streamer();
    int recvData() {};

    uint8_t* getBuffer() { return stream_buffer; }
    long long size() { return size; }
};