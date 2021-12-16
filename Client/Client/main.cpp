#include "Network.h"
#include "Client.h"
#include "Streamer.h"
int main() {
    Client client("165.246.39.22", "11000");
    client.establish_network();
    client.cleanNetwork();
    SOCKET sock = client.getServerSock();
    Streamer stream(&client);

    int sz = stream.recvData();
    uint8_t* buffer = stream.getBuffer();

    FILE* fp = fopen("output.mp4", "wb");
    fwrite(buffer, sizeof(uint8_t), sz, fp);
    fclose(fp);

    return 0;
}