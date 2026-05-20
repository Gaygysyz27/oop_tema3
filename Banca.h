#pragma once
#include <string>
#include <vector>
#include "Client.h"

class Banca {
    std::vector<Client> clienti;

public:
    void adaugaClient(const Client& client);
    void adaugaCreditPentruClient(const std::string& nume, const std::shared_ptr<Credit>& credit);
    void afisare() const;
    Client* gasesteClient(const std::string& nume);
};
