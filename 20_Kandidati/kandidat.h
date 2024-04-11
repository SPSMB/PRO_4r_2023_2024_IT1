#ifndef KANDIDAT_H
#define KANDIDAT_H

#include <QListWidgetItem>
#include <QDateTime>
#include <QDebug>

class Kandidat : public QListWidgetItem
{

public:
    QString k_jmeno;
    QString k_prijmeni;
    QString k_bydliste;
    int k_narozen;
    QString k_schopnosti;
    QString k_foto;

    QString k_stav; // mozne stavy: novy, schvalen, prijat, zamitnut
    QDateTime k_posledniZmena; // cas, kdy doslo k posledni zmene

    Kandidat(QString jmeno, QString prijmeni, int narozen, QString foto);
    QString toString();
    QString toABCString();
    QString stav(); // vraci aktualni stav kandidata
    void posunStav(bool rozhodnuti);
    int vek();
};

#endif // KANDIDAT_H
