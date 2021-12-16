#pragma once
#include "Network.h"

class Server : public Network {
private:
    struct sockaddr_in client_addr;
    SOCKET cli_sock;
    int len_addr;

public:
    Server(std::string );
    ~Server();
    int establish_network();
    void createSocket();
    void bindSocket();
    void listening();
    void cleanNetwork();

    struct sockaddr_in getClientAddr();
    SOCKET getClientSock();
};