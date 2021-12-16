#include "Streamer.h"

Streamer::Streamer(Network* opaque) {
    SOCKET s = opaque->getServerSock();
    this->sock = &s;
    this->serv_addr = &opaque->getServerAddr();
    stream_buffer = new uint8_t[8192 * 8192];
}

Streamer::~Streamer() {
    delete[] stream_buffer;
}

int Streamer::recvData() {
    int readBytes = 0;
    long totalReadBytes = 0;

    char buf[BUFSIZE];
    readBytes = recv(*sock, (char*)stream_buffer, BUFSIZE, 0);
    szData = atoi(buf);
    while (totalReadBytes != szData) {
        memset(buf, 0, BUFSIZE);
        readBytes = recv(*sock, (char*)stream_buffer, BUFSIZE, 0);
        totalReadBytes += readBytes;

        if (readBytes == SOCKET_ERROR) {
            perror("[Streamer] Read error");
            exit(1);
        }
    }
    return totalReadBytes;
}