#include "Client.h"
#include "CreditAuto.h"
#include <iostream>
#include <utility>

Client::Client(const std::string& numeNou) : nume(numeNou) {}

Client::Client(const Client& other) : nume(other.nume) {
    for(const auto& credit : other.credite)
        credite.push_back(credit->clone());
}

Client& Client::operator=(Client other) {
    swap(other);
    return *this;
}

void Client::swap(Client& other) noexcept {
    using std::swap;
    swap(nume, other.nume);
    swap(credite, other.credite);
}

const std::string& Client::getNume() const {
    return nume;
}

void Client::adaugaCredit(const std::shared_ptr<Credit>& credit) {
    credite.push_back(credit);
}

double Client::calculeazaTotalRata() const {
    double total = 0;

    for(const auto& credit : credite)
        total += credit->calculeazaRata();

    return total;
}

double Client::calculeazaTotalRambursat() const {
    double total = 0;

    for(const auto& credit : credite)
        total += credit->calculeazaTotalRambursat();

    return total;
}

int Client::numaraCrediteAuto() const {
    int total = 0;

    for(const auto& credit : credite) {
        if(std::dynamic_pointer_cast<CreditAuto>(credit))
            ++total;
    }

    return total;
}

void Client::afisare() const {
    std::cout << "\nClient: " << nume << "\n";

    for(const auto& credit : credite)
        std::cout << *credit;

    std::cout << "Rata lunara totala: " << calculeazaTotalRata() << "\n";
    std::cout << "Total de rambursat: " << calculeazaTotalRambursat() << "\n";

    if(numaraCrediteAuto() > 0)
        std::cout << "Credite auto gasite: " << numaraCrediteAuto() << "\n";
}
