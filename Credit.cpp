#include "Credit.h"
#include "Exceptii.h"
#include <iostream>

int Credit::numarCrediteCreate = 0;

Credit::Credit(double sumaNoua, int perioadaNoua) : suma(sumaNoua), dobanda(0), perioada(perioadaNoua) {
    if(sumaNoua <= 0)
        throw ExceptieSuma();

    if(perioadaNoua != 6 && perioadaNoua != 12 && perioadaNoua != 24 && perioadaNoua != 36)
        throw ExceptiePerioada();

    ++numarCrediteCreate;
}

double Credit::calculeazaRata() const {
    return calculeazaRataIntern();
}

double Credit::calculeazaTotalRambursat() const {
    return calculeazaRata() * perioada;
}

int Credit::luni() const {
    return perioada;
}

void Credit::afisare(std::ostream& out) const {
    afisareIntern(out);
}

void Credit::afisareIntern(std::ostream& out) const {
    out << "Suma: " << suma
        << " | Perioada: " << perioada
        << " luni | Dobanda: " << dobanda << "%"
        << " | Rata: " << calculeazaRata() << '\n';
}

int Credit::getNumarCrediteCreate() {
    return numarCrediteCreate;
}

std::ostream& operator<<(std::ostream& out, const Credit& credit) {
    credit.afisare(out);
    return out;
}
