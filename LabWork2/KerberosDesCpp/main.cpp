#include "kerberos/kdc.hpp"
#include "server.hpp"
#include "client.hpp"

void initialize(KeyDistributionCenter &kdc, const std::vector<Server> &servers) {
    for (const auto& server : servers) {
        kdc.insert(server);
    }

    Client client1("VladStovba", "12345", kdc);
    Client client2("AntonGaluts", "1234567", kdc);
    kdc.insert(client1);
    kdc.insert(client2);
}

int main() {
    std::vector<Server> servers;
    servers.emplace_back("Server1");
    servers.emplace_back("Server2");
    KeyDistributionCenter kdc;
    initialize(kdc, servers);

    Client vlad("VladStovba", "12345", kdc);
    vlad.connect(servers[0]);
    std::cout << "---------------------------------------------------" << std::endl;
    vlad.connect(servers[1]);
    std::cout << "---------------------------------------------------" << std::endl;
    vlad.connect(servers[0]);
    return 0;
}
