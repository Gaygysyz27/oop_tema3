#include "CreditPrimaCasa.h"
#include "Exceptii.h"
#include <iostream>

CreditPrimaCasa::CreditPrimaCasa(double sumaNoua, int perioadaNoua) : Credit(sumaNoua, perioadaNoua) {
    if(sumaNoua < 55000 || sumaNoua > 95000)
        throw ExceptieSuma();

    if(perioadaNoua == 6) dobanda = 9;
    else if(perioadaNoua == 12) dobanda = 7;
    else if(perioadaNoua == 24) dobanda = 6;
    else if(perioadaNoua == 36) dobanda = 5;
}

double CreditPrimaCasa::calculeazaRataIntern() const {
    return suma * (1 + dobanda / 100) / perioada;
}

void CreditPrimaCasa::afisareIntern(std::ostream& out) const {
    out << "Credit prima casa | ";
    Credit::afisareIntern(out);
}

std::shared_ptr<Credit> CreditPrimaCasa::clone() const {
    return std::make_shared<CreditPrimaCasa>(*this);
}
