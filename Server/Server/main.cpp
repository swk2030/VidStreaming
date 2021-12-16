#include "Network.h"
#include "Server.h"
#include "Client.h"
int main() {
    Server serv("11000");
    serv.establish_network();
    serv.cleanNetwork();
    return 0;
}