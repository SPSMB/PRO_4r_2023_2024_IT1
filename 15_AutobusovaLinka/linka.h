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
    ~Linka();
    void vypisStanice();
    void vlozStanici(QString jmeno);
    Stanice * odeberStanici(QString jmeno);
    Stanice * odeberStanici(Stanice * st);
    Stanice * existuje(QString jmeno);
    void smazPosledni();
    void smazVse();
    void vypisStanice(QString jmeno);

};

#endif // LINKA_H
