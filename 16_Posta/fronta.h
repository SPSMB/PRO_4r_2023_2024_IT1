#ifndef FRONTA_H
#define FRONTA_H

#include "osoba.h"

class Fronta
{
private:
    Osoba * f_prvni;
    Osoba * f_posledni;
    int f_citac;

public:
    Fronta();
    ~Fronta();
    void pridej(Osoba * os);       // enqueue
    Osoba * odeber();              // dequeue
    Osoba * prvni();               // front
    Osoba * posledni();            // back
    bool je_Prazdna();             // is_empty
    QString toString();            // vypis fronty do stringu
};

#endif // FRONTA_H
