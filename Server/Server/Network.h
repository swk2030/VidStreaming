#pragma once
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <windows.h>
#include <string>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

#define BUFSIZE 4096

class Network {
protected:
    WSADATA wsaData;
    struct sockaddr_in server_addr;
    SOCKET serv_sock;
    
    std::string PORT;
public:
    Network(std::string PORT);
    ~Network();
    virtual int establish_network()=0;
    virtual void createSocket()=0;
    virtual void cleanNetwork()=0;

    struct sockaddr_in getServerAddr();
    SOCKET getServerSock();
};