#include "Client.h"
Client::Client(std::string ip, std::string port) :Network(port) {
    IP = ip;
}

Client::~Client() {
    std::cout << "Destroy Client instance...\n";
}

int Client::establish_network() {
    createSocket();
    connectSocket();
    printf("[NETWORK] Client successfully connects with Server\n");
    return 0;
}

void Client::createSocket() {
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    if ((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[Client] Creating socket is failed...");
        exit(1);
    }
    int rcv_buffer_size;
    int sockopt_size = sizeof(rcv_buffer_size);
    getsockopt(serv_sock, SOL_SOCKET, SO_RCVBUF, (char*)&rcv_buffer_size, &sockopt_size);
    printf("[Client] Receive buffer : %d\n", rcv_buffer_size);
    printf("[Client] Creating socket is successfully completed!\n");
}

void Client::connectSocket() {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP.c_str());
    server_addr.sin_port = htons(atoi(PORT.c_str()));

    if (connect(serv_sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        perror("[Client] Socket Connection Error.");
        exit(1);
    }
}

void Client::cleanNetwork() {
    if (serv_sock)closesocket(serv_sock);
    printf("[Client] All network sockets are closed\n");
}