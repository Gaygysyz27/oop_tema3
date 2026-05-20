#pragma once
#include <iosfwd>
#include <memory>

class Credit {
    static int numarCrediteCreate;

protected:
    double suma;
    double dobanda;
    int perioada;

    virtual double calculeazaRataIntern() const = 0;
    virtual void afisareIntern(std::ostream& out) const;

public:
    Credit(double suma, int perioada);
    virtual ~Credit() = default;

    double calculeazaRata() const;
    double calculeazaTotalRambursat() const;
    int luni() const;

    void afisare(std::ostream& out) const;
    virtual std::shared_ptr<Credit> clone() const = 0;

    static int getNumarCrediteCreate();

    friend std::ostream& operator<<(std::ostream& out, const Credit& credit);
};
