#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>

using namespace std;

class Test
{
private:
    int ** t_vysledky; // 2D pole pro vysledky
    int t_pocSkupin; // pocet skupin
    int * t_ptvs; // pocet testu ve skupine - je to pole

    // Statisticka data
    int t_celkovySoucet; // celkovy soucet ze vsech skupin
    int * t_souctyVeSkupinach; // soucty ve skupinach
    int * t_prumeryVeSkupinach; // prumery ve skupinach
    int t_maximum; // min ze vsech skupin
    int t_minimum; // max ze vsech skupin

    ifstream t_soubor; // tady budu cist data ze souboru

public:
    Test();
    ~Test();
    void nactiData();
    void vypisVysledky();
};

#endif // TEST_H
