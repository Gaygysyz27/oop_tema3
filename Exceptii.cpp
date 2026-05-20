#include "Exceptii.h"

ExceptieAplicatie::ExceptieAplicatie(const std::string& mesajNou) : mesaj(mesajNou) {}

const char* ExceptieAplicatie::what() const noexcept {
    return mesaj.c_str();
}

ExceptieSuma::ExceptieSuma() : ExceptieAplicatie("Suma nu se incadreaza pentru creditul ales") {}

ExceptiePerioada::ExceptiePerioada() : ExceptieAplicatie("Perioada trebuie sa fie 6, 12, 24 sau 36 luni") {}

ExceptieTipCredit::ExceptieTipCredit() : ExceptieAplicatie("Tip de credit necunoscut") {}

ExceptieFisier::ExceptieFisier() : ExceptieAplicatie("Fisierul date.txt nu poate fi folosit") {}
