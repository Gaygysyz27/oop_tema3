#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Credit.h"

class Client {
    std::string nume;
    std::vector<std::shared_ptr<Credit>> credite;

public:
    explicit Client(const std::string& nume);
    Client(const Client& other);
    Client& operator=(Client other);

    void swap(Client& other) noexcept;
    const std::string& getNume() const;

    void adaugaCredit(const std::shared_ptr<Credit>& credit);
    double calculeazaTotalRata() const;
    double calculeazaTotalRambursat() const;
    int numaraCrediteAuto() const;

    void afisare() const;
};
