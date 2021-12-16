#include "Network.h"

Network::Network(std::string PORT) {
    this->PORT = PORT;
}

Network::~Network() {
    std::cout << "Destroy Network instance...\n";
}

struct sockaddr_in Network::getServerAddr() {
    return server_addr;
}
SOCKET Network::getServerSock() {
    return serv_sock;
}