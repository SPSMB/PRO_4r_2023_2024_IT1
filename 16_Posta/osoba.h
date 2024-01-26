#ifndef OSOBA_H
#define OSOBA_H
#include <QString>

class Osoba
{
private:
public:
    QString jmeno;
    int id;
    Osoba * dalsi;
    Osoba();
};

#endif // OSOBA_H
