#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Network.h"
#include "Server.h"

class Streamer {
private:
    SOCKET cli_sock;
    struct sockaddr_in serv_addr;
    uint8_t* stream_buffer;
    long long szData;
    long long sz;
public:
    Streamer(SOCKET, struct sockaddr_in);
    void recvRequest();
    void sendData(const char* filename);    //single input
    void sendData(std::string filename);    //single input
    void sendData(std::string* filenames) {};  //multiple input

    long long size() { return sz; }
};