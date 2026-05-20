#pragma once
#include <exception>
#include <string>

class ExceptieAplicatie : public std::exception {
    std::string mesaj;

public:
    explicit ExceptieAplicatie(const std::string& mesajNou);
    const char* what() const noexcept override;
};

class ExceptieSuma : public ExceptieAplicatie {
public:
    ExceptieSuma();
};

class ExceptiePerioada : public ExceptieAplicatie {
public:
    ExceptiePerioada();
};

class ExceptieTipCredit : public ExceptieAplicatie {
public:
    ExceptieTipCredit();
};

class ExceptieFisier : public ExceptieAplicatie {
public:
    ExceptieFisier();
};
