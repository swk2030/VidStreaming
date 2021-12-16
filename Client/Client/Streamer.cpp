#include "Streamer.h"

Streamer::Streamer(SOCKET* sock, struct sockaddr_in* addr) {
    this->cli_sock = sock;
    this->serv_addr = addr;
}

void Streamer::sendData(std::string filename) {
    int sendBytes;
    long totalSendBytes;
    long szFile;
    char buf[BUFSIZE];

    printf("[Streamer] Start sending a data to client\n");
    FILE* fp;
    fp = fopen(filename.c_str(), "rb");
    if (fp == NULL) {
        perror("[Streamer] File open error ");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    szFile = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    totalSendBytes = 0;
    sendBytes = send(*cli_sock, buf, sizeof(buf), 0);
    while ((sendBytes = fread(buf, sizeof(char), sizeof(buf), fp)) > 0) {
        send(*cli_sock, buf, sendBytes, 0);
        totalSendBytes += sendBytes;
    }
    printf("[Streamser] End sending a data to client\n");
    fclose(fp);
}