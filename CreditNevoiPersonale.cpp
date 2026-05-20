#include "CreditNevoiPersonale.h"
#include "Exceptii.h"
#include <iostream>

CreditNevoiPersonale::CreditNevoiPersonale(double sumaNoua, int perioadaNoua) : Credit(sumaNoua, perioadaNoua) {
    if(sumaNoua < 25000 || sumaNoua > 50000)
        throw ExceptieSuma();

    if(perioadaNoua == 6) dobanda = 14;
    else if(perioadaNoua == 12) dobanda = 12;
    else if(perioadaNoua == 24) dobanda = 11;
    else if(perioadaNoua == 36) dobanda = 10;
}

double CreditNevoiPersonale::calculeazaRataIntern() const {
    return suma * (1 + dobanda / 100) / perioada;
}

void CreditNevoiPersonale::afisareIntern(std::ostream& out) const {
    out << "Credit nevoi personale | ";
    Credit::afisareIntern(out);
}

std::shared_ptr<Credit> CreditNevoiPersonale::clone() const {
    return std::make_shared<CreditNevoiPersonale>(*this);
}
