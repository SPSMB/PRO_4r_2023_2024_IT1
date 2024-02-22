#ifndef MORSEOVKA_H
#define MORSEOVKA_H
#include "uzel.h"
#include <string>

using namespace std;

class Morseovka
{
    Uzel * koren;
public:
    Morseovka();
    Uzel * vytvorStrom();
    Uzel * novyUzel(char z, Uzel * t, Uzel * c);
    void dekoduj(string & vstup, string & vystup);
};

#endif // MORSEOVKA_H
