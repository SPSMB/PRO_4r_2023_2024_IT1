#ifndef ZASOBNIK_H
#define ZASOBNIK_H

#include "osoba.h"
#include <QDebug>

class Zasobnik
{
private:
    Osoba* * z_poleOsob; // mam pole, prvky jsou ukazatele na Osoby
    int z_ukazatel; // ukazuje na prvni volne misto = prvni volny index v poli
    int z_kapacita; // kolik prvku se vejde do pole
    int z_pocatecniKapacita; // kolik se vejde prvku na zacatku

public:
    Zasobnik();
    ~Zasobnik();
    void push(Osoba * os); // vlozi ukazatel na novou osobu na vrchol zasobniku
    Osoba *pop(void); // odebere ukazatel na osobu z vrcholu zasobniku
    void top(void); // vypise, kdo je na vrcholu zasobniku
    bool is_empty(void); // vrati true, jestli je prazdny, jinak false
    QString toString(void); // vypise cely zasobnik do stringu

    void kontrolujKapacitu(); // kontroluje, jestli doslo k naplneni zasobniku
    void zmenPole(bool zvetsit); // nahrazuje 2 funkce - zvetsiPole(); a zmensiPole();
};


#endif // ZASOBNIK_H
