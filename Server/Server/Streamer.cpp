#include "Streamer.h"

Streamer::Streamer(SOCKET s, struct sockaddr_in s_in) {
    this->cli_sock = s;
    this->serv_addr = s_in;
}

void Streamer::recvRequest() {
    char filename[256];
    int length = recv(cli_sock, filename, sizeof(filename), 0);
    filename[length] = NULL;
    sendData(filename);
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
    printf("[LF Server] File size : %d\n", szFile);
    totalSendBytes = 0;
    _snprintf(buf, sizeof(buf), "%d", szFile);
    printf("size of buf : %d\n", sizeof(buf));
    sendBytes = send(cli_sock, buf, sizeof(buf), 0);
    while ((sendBytes = fread(buf, sizeof(char), sizeof(buf), fp)) > 0) {
        send(cli_sock, buf, sendBytes, 0);
        totalSendBytes += sendBytes;
        //printf("In progress: sendbytes %d/%d Byte(s)\n", totalSendBytes, szFile);
    }
    printf("[Streamser] End sending a data to client\n");
    fclose(fp);
}

void Streamer::sendData(const char* filename) {
    int sendBytes;
    long totalSendBytes;
    long szFile;
    char buf[BUFSIZE];

    printf("[Streamer] Start sending a data to client\n");
    FILE* fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("[Streamer] File open error ");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    szFile = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("[LF Server] File size : %d\n", szFile);
    totalSendBytes = 0;
    _snprintf(buf, sizeof(buf), "%d", szFile);
    printf("size of buf : %d\n", sizeof(buf));
    sendBytes = send(cli_sock, buf, sizeof(buf), 0);
    while ((sendBytes = fread(buf, sizeof(char), sizeof(buf), fp)) > 0) {
        send(cli_sock, buf, sendBytes, 0);
        totalSendBytes += sendBytes;
        //printf("In progress: sendbytes %d/%d Byte(s)\n", totalSendBytes, szFile);
    }
    printf("[Streamser] End sending a data to client\n");
    fclose(fp);
}