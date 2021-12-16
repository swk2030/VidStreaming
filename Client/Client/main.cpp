#include "Network.h"
#include "Client.h"
int main() {
    Client client("165.246.39.22", "11000");
    client.establish_network();
    client.cleanNetwork();
    return 0;
}