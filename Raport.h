#pragma once
#include <iostream>

template <typename T>
class Raport {
private:
    T valoare;

public:
    explicit Raport(const T& valoareNoua)
        : valoare(valoareNoua) {}

    void afiseaza(const std::string& mesaj) const {
        std::cout << mesaj << valoare << "\n";
    }

    const T& getValoare() const {
        return valoare;
    }
};

template <typename T>
T valoareMaiMare(const T& a, const T& b) {
    return a > b ? a : b;
}