#include "CreditAuto.h"
#include "Exceptii.h"
#include <iostream>

CreditAuto::CreditAuto(double sumaNoua, int perioadaNoua) : Credit(sumaNoua, perioadaNoua), taxaAdministrare(500) {
    if(sumaNoua < 30000 || sumaNoua > 75000)
        throw ExceptieSuma();

    if(perioadaNoua == 6) dobanda = 12;
    else if(perioadaNoua == 12) dobanda = 10;
    else if(perioadaNoua == 24) dobanda = 9;
    else if(perioadaNoua == 36) dobanda = 8;
}

double CreditAuto::calculeazaRataIntern() const {
    return (suma + taxaAdministrare + suma * dobanda / 100) / perioada;
}

void CreditAuto::afisareIntern(std::ostream& out) const {
    out << "Credit auto | ";
    Credit::afisareIntern(out);
}

std::shared_ptr<Credit> CreditAuto::clone() const {
    return std::make_shared<CreditAuto>(*this);
}
