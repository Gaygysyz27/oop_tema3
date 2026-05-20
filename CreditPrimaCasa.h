#pragma once
#include "Credit.h"

class CreditPrimaCasa : public Credit {
protected:
    double calculeazaRataIntern() const override;
    void afisareIntern(std::ostream& out) const override;

public:
    CreditPrimaCasa(double suma, int perioada);
    std::shared_ptr<Credit> clone() const override;
};
