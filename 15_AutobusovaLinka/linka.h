#ifndef LINKA_H
#define LINKA_H
#include "stanice.h"
#include <iostream>

using namespace std;

class Linka
{
private:
    Stanice * l_posledni;
public:
    Linka();
    void vypisStanice();
    void vlozStanici(QString jmeno);
    Stanice * odeberStanici(Stanice * st);
    void smazPosledni();
    void smazVse();
};

#endif // LINKA_H
