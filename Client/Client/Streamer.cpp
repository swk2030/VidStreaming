#define _CRT_SECURE_NO_WARNINGS
#include "Streamer.h"

Streamer::Streamer(SOCKET s, struct sockaddr_in s_in) {
    this->sock = s;
    this->serv_addr = s_in;
    stream_buffer = new uint8_t[311040000];
    memset(stream_buffer, 0, sizeof(uint8_t)*(311040000));
}

Streamer::~Streamer() {
    delete[] stream_buffer;
}

int Streamer::recvData() {
    int readBytes = 0;
    long totalReadBytes = 0;

    char buf[BUFSIZE];
    readBytes = recv(sock, buf, BUFSIZE, 0);
    szData = atoi(buf);
    uint8_t* data_set = stream_buffer;
    while (totalReadBytes != szData) {
        memset(buf, 0, BUFSIZE);
        readBytes = recv(sock, (char*)data_set, BUFSIZE, 0);
        totalReadBytes += readBytes;
        if (readBytes == SOCKET_ERROR) {
            perror("[Streamer] Read error");
            exit(1);
        }
        data_set += readBytes;
    }
    return totalReadBytes;
}