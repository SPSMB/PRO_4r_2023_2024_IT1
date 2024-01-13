#ifndef STANICE_H
#define STANICE_H
#include <QString>

class Stanice
{
public:
    QString jmeno;
    Stanice * dalsi;
    Stanice * predchozi;
    Stanice();
};

#endif // STANICE_H
