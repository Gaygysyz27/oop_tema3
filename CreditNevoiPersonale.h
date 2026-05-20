#pragma once
#include "Credit.h"

class CreditNevoiPersonale : public Credit {
protected:
    double calculeazaRataIntern() const override;
    void afisareIntern(std::ostream& out) const override;

public:
    CreditNevoiPersonale(double suma, int perioada);
    std::shared_ptr<Credit> clone() const override;
};
