#include "CreditIpotecar.h"
#include "Exceptii.h"
#include <iostream>

CreditIpotecar::CreditIpotecar(double sumaNoua, int perioadaNoua) : Credit(sumaNoua, perioadaNoua) {
    if(sumaNoua < 65000 || sumaNoua > 100000)
        throw ExceptieSuma();

    if(perioadaNoua == 6) dobanda = 10;
    else if(perioadaNoua == 12) dobanda = 8;
    else if(perioadaNoua == 24) dobanda = 7;
    else if(perioadaNoua == 36) dobanda = 6;
}

double CreditIpotecar::calculeazaRataIntern() const {
    return suma * (1 + dobanda / 100) / perioada;
}

void CreditIpotecar::afisareIntern(std::ostream& out) const {
    out << "Credit ipotecar | ";
    Credit::afisareIntern(out);
}

std::shared_ptr<Credit> CreditIpotecar::clone() const {
    return std::make_shared<CreditIpotecar>(*this);
}
