#pragma once
#include "Network.h"

class Client :public Network {
private:
    std::string IP;

public:
    Client(std::string, std::string);
    ~Client();
    int establish_network();
    void createSocket();
    void connectSocket();
    void cleanNetwork();
};