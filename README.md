# Proiect POO - Sistem de gestionare a creditelor bancare

## Descrierea problemei

Proiectul reprezinta o aplicatie pentru gestionarea creditelor bancare oferite clientilor unei banci. Aplicatia permite stocarea clientilor si a mai multor tipuri de credite, precum credite auto, ipotecare, de nevoi personale si Prima Casa. Pentru fiecare tip de credit se calculeaza rata lunara folosind formule diferite, specifice fiecarui tip de imprumut.

Datele aplicatiei sunt citite din fisier text pentru a evita introducerea repetata de date de la tastatura. Aplicatia permite afisarea clientilor si a creditelor acestora, calcularea ratelor, afisarea numarului total de credite create si adaugarea manuala de clienti noi.

Proiectul foloseste concepte importante de programare orientata pe obiect precum mostenirea, polimorfismul, functiile virtuale pure, clase abstracte, exceptii, template-uri si design patterns.

---

# Modul de rezolvare

## Structura proiectului

Codul este separat in fisiere `.h` si `.cpp` pentru o organizare mai clara:

* fisierele `.h` contin declaratiile claselor si functiilor
* fisierele `.cpp` contin implementarile

Aplicatia este organizata pe mai multe clase:

* `Credit` - clasa baza abstracta
* `CreditAuto`
* `CreditIpotecar`
* `CreditNevoiPersonale`
* `CreditPrimaCasa`
* `Client`
* `Banca`
* `CreditFactory`
* `Raport<T>`

---

# Mostenire si polimorfism

Clasa abstracta `Credit` reprezinta baza ierarhiei. Din aceasta deriva mai multe tipuri de credite:

* `CreditAuto`
* `CreditIpotecar`
* `CreditNevoiPersonale`
* `CreditPrimaCasa`

Clasa baza contine functii virtuale pure pentru calculul ratelor si afisare. Aplicatia foloseste polimorfism prin intermediul pointerilor:

```cpp
std::vector<std::shared_ptr<Credit>>
```

Astfel, programul poate lucra generic cu toate tipurile de credite.

---

# Constructor virtual (clone)

Pentru copiere polimorfica am folosit functia:

```cpp
clone()
```

Fiecare clasa derivata implementeaza propria versiune de `clone`, astfel incat obiectele sa fie copiate corect chiar daca sunt accesate prin pointer la baza.

---

# Copy constructor si operator=

Clasa `Client` suprascrie copy constructorul si operatorul `=` folosind tehnica copy-swap pentru a realiza copieri sigure ale vectorului de credite.

---

# Dynamic cast

Aplicatia foloseste:

```cpp
std::dynamic_pointer_cast
```

pentru verificarea tipului real al unui obiect din ierarhia `Credit`.

---

# Exceptii

Aplicatia foloseste o ierarhie proprie de exceptii:

* `ExceptieAplicatie`
* `ExceptieSuma`
* `ExceptiePerioada`
* `ExceptieTipCredit`
* `ExceptieFisier`

Exceptiile sunt aruncate in caz de date invalide sau erori de citire si sunt tratate in `main` folosind `try/catch`.

---

# Template-uri

Aplicatia contine:

* o clasa template:

```cpp
template <typename T>
class Raport
```

* o functie template:

```cpp
template <typename T>
T valoareMaiMare(...)
```

Clasa template permite generarea de rapoarte pentru tipuri diferite de date fara duplicarea codului.

---

# Design Patterns

## Factory Pattern

Pattern-ul este implementat prin clasa:

```cpp
CreditFactory
```

Aceasta centralizeaza logica de creare a obiectelor de tip `Credit`, in functie de tipul citit din fisier sau introdus de utilizator.

Avantaje:

* cod mai organizat
* separarea responsabilitatilor
* adaugare usoara de noi tipuri de credite

---

## Prototype Pattern

Pattern-ul este implementat prin functia:

```cpp
clone()
```

Acesta permite copierea polimorfica a obiectelor din ierarhia `Credit`.

---

# STL si smart pointers

Proiectul foloseste:

* `std::vector`
* `std::string`
* `std::shared_ptr`

pentru gestionarea eficienta si sigura a memoriei.

---

# Fisiere

Datele aplicatiei sunt citite din fisierul:

```text
date.txt
```

Acest lucru reduce introducerea manuala de date si permite testarea rapida a aplicatiei.

---

# Cerinte suplimentare

Proiectul respecta:

* separarea codului in `.h` si `.cpp`
* functii virtuale pure
* mostenire
* polimorfism
* exceptii
* template-uri
* design patterns
* STL
* const correctness
* fara memory leaks evidente
* commit separat pentru clasa derivata noua
* tag git `v0.2`

---

# Bibliografie

* Curs POO - Mostenire si polimorfism
* Curs POO - Clase abstracte si functii virtuale
* Curs POO - Smart pointers
* Curs POO - Template-uri
* Curs POO - Design Patterns
* Curs POO - Exceptii
* Documentatie cppreference.com
