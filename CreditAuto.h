#pragma once
#include "Credit.h"

class CreditAuto : public Credit {
    double taxaAdministrare;

protected:
    double calculeazaRataIntern() const override;
    void afisareIntern(std::ostream& out) const override;

public:
    CreditAuto(double suma, int perioada);
    std::shared_ptr<Credit> clone() const override;
};
