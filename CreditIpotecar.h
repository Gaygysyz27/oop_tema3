#pragma once
#include "Credit.h"

class CreditIpotecar : public Credit {
protected:
    double calculeazaRataIntern() const override;
    void afisareIntern(std::ostream& out) const override;

public:
    CreditIpotecar(double suma, int perioada);
    std::shared_ptr<Credit> clone() const override;
};
