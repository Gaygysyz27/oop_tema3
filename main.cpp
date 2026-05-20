#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include "Banca.h"
#include "CreditFactory.h"
#include "Exceptii.h"

std::string tipDinOptiune(int opt) {
    if(opt == 1) return "auto";
    if(opt == 2) return "ipotecar";
    if(opt == 3) return "nevoi";
    throw ExceptieTipCredit();
}

std::ifstream deschideFisierCitire() {
    std::ifstream fin("date.txt");
    if(fin)
        return fin;

    fin.open("../date.txt");
    return fin;
}

void citesteDinFisier(Banca& banca) {
    std::ifstream fin = deschideFisierCitire();

    if(!fin) {
        std::ofstream creare("date.txt");
        if(!creare)
            throw ExceptieFisier();
        std::cout << "Fisierul date.txt a fost creat automat.\n";
        return;
    }

    std::string linie;

    while(std::getline(fin, linie)) {
        if(linie.empty())
            continue;

        std::stringstream ss(linie);
        std::string nume, tip, sumaText, perioadaText;

        std::getline(ss, nume, ';');
        std::getline(ss, tip, ';');
        std::getline(ss, sumaText, ';');
        std::getline(ss, perioadaText, ';');

        try {
            double suma = std::stod(sumaText);
            int perioada = std::stoi(perioadaText);
            banca.adaugaCreditPentruClient(nume, CreditFactory::creeazaCredit(tip, suma, perioada));
        }
        catch(const std::exception&) {
            std::cout << "Linie invalida ignorata: " << linie << "\n";
        }
    }
}

void salveazaClientInFisier(const std::string& nume, const std::string& tip, double suma, int perioada) {
    std::ofstream fout("date.txt", std::ios::app);
    if(!fout)
        throw ExceptieFisier();

    fout << nume << ";" << tip << ";" << suma << ";" << perioada << "\n";
}

void adaugaClientManual(Banca& banca) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string nume;
    std::cout << "Nume client: ";
    std::getline(std::cin, nume);

    int optTip;
    std::cout << "1-auto 2-ipotecar 3-nevoi: ";
    std::cin >> optTip;

    double suma;
    std::cout << "Suma: ";
    std::cin >> suma;

    int perioada;
    std::cout << "Perioada (6/12/24/36): ";
    std::cin >> perioada;

    try {
        std::string tip = tipDinOptiune(optTip);
        auto credit = CreditFactory::creeazaCredit(tip, suma, perioada);

        banca.adaugaCreditPentruClient(nume, credit);
        salveazaClientInFisier(nume, tip, suma, perioada);

        std::cout << "Client adaugat si salvat in date.txt.\n";
    }
    catch(const std::exception& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
}

void calculeazaPentruClient(Banca& banca) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string nume;
    std::cout << "Nume client: ";
    std::getline(std::cin, nume);

    Client* client = banca.gasesteClient(nume);

    if(client) {
        std::cout << "Rata lunara totala: " << client->calculeazaTotalRata() << "\n";
        std::cout << "Total de rambursat: " << client->calculeazaTotalRambursat() << "\n";
    }
    else {
        std::cout << "Client inexistent.\n";
    }
}

int main() {
    Banca banca;

    try {
        citesteDinFisier(banca);
    }
    catch(const std::exception& e) {
        std::cout << "Eroare la pornire: " << e.what() << "\n";
    }

    int opt;

    do {
        std::cout << "\n1. Afisare clienti\n";
        std::cout << "2. Adauga client\n";
        std::cout << "3. Calculeaza rate\n";
        std::cout << "4. Numar credite create\n";
        std::cout << "0. Iesire\n";
        std::cout << "Alege: ";
        std::cin >> opt;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Optiune invalida.\n";
            continue;
        }

        if(opt == 1)
            banca.afisare();
        else if(opt == 2)
            adaugaClientManual(banca);
        else if(opt == 3)
            calculeazaPentruClient(banca);
        else if(opt == 4)
            std::cout << "Credite create: " << Credit::getNumarCrediteCreate() << "\n";
        else if(opt != 0)
            std::cout << "Optiune invalida.\n";

    } while(opt != 0);

    return 0;
}
