#define _CRT_SECURE_NO_WARNINGS
#include "Network.h"
#include "Client.h"
#include "Streamer.h"
int main() {
    Client client("165.246.39.22", "11000");
    client.establish_network();
    SOCKET sock = client.getServerSock();
    Streamer stream(client.getServerSock(), client.getServerAddr());

    int sz = stream.recvData();
    uint8_t* buffer = stream.getBuffer();
    printf("size : %d\n", sz);
    FILE* fp = fopen("output.yuv", "wb");
    fwrite(buffer, sizeof(uint8_t), sz, fp);
    fclose(fp);
    client.cleanNetwork();

    return 0;
}