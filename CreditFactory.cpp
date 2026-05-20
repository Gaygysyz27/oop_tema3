#include "CreditFactory.h"
#include "CreditAuto.h"
#include "CreditIpotecar.h"
#include "CreditNevoiPersonale.h"
#include "Exceptii.h"

std::shared_ptr<Credit> CreditFactory::creeazaCredit(const std::string& tip, double suma, int perioada) {
    if(tip == "auto")
        return std::make_shared<CreditAuto>(suma, perioada);

    if(tip == "ipotecar")
        return std::make_shared<CreditIpotecar>(suma, perioada);

    if(tip == "nevoi")
        return std::make_shared<CreditNevoiPersonale>(suma, perioada);

    throw ExceptieTipCredit();
}
