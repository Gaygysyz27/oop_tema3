#include "Banca.h"
#include <iostream>

void Banca::adaugaClient(const Client& client) {
    clienti.push_back(client);
}

void Banca::adaugaCreditPentruClient(const std::string& nume, const std::shared_ptr<Credit>& credit) {
    Client* clientExistent = gasesteClient(nume);

    if(clientExistent) {
        clientExistent->adaugaCredit(credit);
        return;
    }

    Client clientNou(nume);
    clientNou.adaugaCredit(credit);
    adaugaClient(clientNou);
}

void Banca::afisare() const {
    if(clienti.empty()) {
        std::cout << "Nu exista clienti.\n";
        return;
    }

    for(const auto& client : clienti)
        client.afisare();
}

Client* Banca::gasesteClient(const std::string& nume) {
    for(auto& client : clienti)
        if(client.getNume() == nume)
            return &client;

    return nullptr;
}
