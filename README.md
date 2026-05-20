# Sistem de gestionare credite bancare

## Enunt
Aplicatia gestioneaza creditele unor clienti ai unei banci. Pentru fiecare client se retin numele si lista de credite. Un credit poate fi auto, ipotecar sau de nevoi personale, iar fiecare tip are propriile reguli pentru suma acceptata, perioada si dobanda. Programul citeste date din fisierul `date.txt`, permite adaugarea unui client prin meniu si calculeaza rata lunara, suma totala de rambursat si numarul de credite create.

## Date de intrare
Fisierul `date.txt` are linii de forma:

```text
Nume Client;tip;suma;perioada
```

Tipurile folosite initial sunt `auto`, `ipotecar` si `nevoi`. Perioada acceptata este 6, 12, 24 sau 36 luni.

## Mod de rezolvare
Clasa abstracta `Credit` este baza ierarhiei. Ea contine datele comune: suma, dobanda si perioada. Clasele `CreditAuto`, `CreditIpotecar` si `CreditNevoiPersonale` mostenesc clasa `Credit` si implementeaza calculul ratei. Clasa `Client` contine un vector de `std::shared_ptr<Credit>`, deci functiile virtuale sunt apelate prin pointeri la clasa de baza. Clasa `Banca` pastreaza clientii si cauta clientul dupa nume.

Pentru crearea creditelor am folosit un Factory simplu, in clasa `CreditFactory`. Astfel, codul din `main` nu mai construieste direct fiecare tip de credit, ci cere fabricii sa creeze obiectul potrivit dupa textul citit din fisier sau ales in meniu.

## Cerinte bifate
- cod separat in fisiere `.h` si `.cpp`
- clasa de baza proprie: `Credit`
- minim 3 clase derivate: `CreditAuto`, `CreditIpotecar`, `CreditNevoiPersonale`
- functie virtuala pura specifica temei: calculul ratei
- afisare virtuala cu interfata non-virtuala
- constructorii derivatelor apeleaza constructorul bazei
- `Client` are atribut de tip pointer la baza: `std::vector<std::shared_ptr<Credit>>`
- functii virtuale apelate prin pointer de baza
- constructor virtual `clone` pentru copiere polimorfica
- copy constructor si operator= cu copy and swap in `Client`
- `std::dynamic_pointer_cast` folosit pentru numararea creditelor auto
- exceptii proprii: `ExceptieAplicatie`, `ExceptieSuma`, `ExceptiePerioada`, `ExceptieTipCredit`, `ExceptieFisier`
- exceptiile sunt folosite in constructori, factory si la fisiere
- atribut si functie static: numarul total de credite create
- STL: `vector`, `string`, `shared_ptr`
- metode `const` unde obiectul nu se modifica
- operator `<<`
- citire din fisier text
- design pattern: Factory
- design pattern simplu: Prototype prin metoda `clone`

## Commit final pentru cerinta cu derivata noua
Pentru cerinta cu o clasa derivata adaugata la final, se poate adauga separat clasa `CreditPrimaCasa`, apoi se face commit separat si tag:

```bash
git add .
git commit -m "Adauga CreditPrimaCasa"
git tag v0.2
```

In arhiva finala aceasta clasa poate fi integrata in `CreditFactory` si in meniu.

## Bibliografie
- Curs POO - mostenire si functii virtuale
- Curs POO - pointeri si smart pointers
- Curs POO - exceptii
- Curs POO - fisiere text
- Materiale laborator - exemple design patterns
- https://en.cppreference.com/w/cpp/memory/shared_ptr
- https://en.cppreference.com/w/cpp/memory/shared_ptr/pointer_cast
