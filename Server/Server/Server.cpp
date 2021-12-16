#include "Server.h"

Server::Server(std::string port) :Network(port) {

}

Server::~Server() {
    std::cout << "Destroy Server instance...\n";
}

int Server::establish_network() {
    createSocket();
    bindSocket();
    listening();
    len_addr = sizeof(client_addr);
    cli_sock = accept(serv_sock, (SOCKADDR*)&client_addr, &len_addr);
    if (cli_sock) {
        return 0;
    }
    return -1;
}

void Server::createSocket() {
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    if ((serv_sock = socket(AF_INET, SOCK_STREAM, 0))<0){
        perror("[Server] Creating socket is failed...");
        exit(1);
    }
    std::cout << "[Server] Creating socket is successfully completed...\n";
}

void Server::bindSocket() {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(PORT.c_str()));

    if (bind(serv_sock, (SOCKADDR*)&server_addr, sizeof(server_addr))) {
        perror("[Server] Binding socket is failed...");
        exit(1);
    }
    printf("[Server] Binding socket is successfully completed!\n");
}

void Server::listening() {
    if (listen(serv_sock, 5) == SOCKET_ERROR) {
        perror("[Server] Listening socket is failed...");
        exit(1);
    }
    printf("[Server] This server is listening...\n");
}

void Server::cleanNetwork() {
    if (serv_sock) closesocket(serv_sock);
    if (cli_sock) closesocket(cli_sock);
    printf("[Server] All network sockets are closed\n");
}
struct sockaddr_in Server::getClientAddr() {
    return client_addr;
}

SOCKET Server::getClientSock() {
    return cli_sock;
}