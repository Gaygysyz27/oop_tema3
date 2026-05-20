#pragma once
#include <memory>
#include <string>
#include "Credit.h"

class CreditFactory {
public:
    static std::shared_ptr<Credit> creeazaCredit(const std::string& tip, double suma, int perioada);
};
