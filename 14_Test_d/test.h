#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Test
{
private:
    vector< vector<int>> t_vysledky; // 2D vector pro vysledky
    int t_pocSkupin; // pocet skupin
    vector<int> t_ptvs; // pocet testu ve skupine - je to pole

    // Statisticka data
    int t_celkovySoucet; // celkovy soucet ze vsech skupin
    float t_celkovyPrumer; // celkovy prumer ze vsech skupin
    int t_celkovyPocet; // celkovy pocet vsech testu
    vector<int> t_souctyVeSkupinach; // soucty ve skupinach
    vector<float> t_prumeryVeSkupinach; // prumery ve skupinach
    vector<bool> t_maximaVeskupinach; // skupiny, kde bylo dosazeno maximalniho vysledku
    int t_cns; // cislo (id) nejlepsi skupiny
    int t_maximum; // min ze vsech skupin
    int t_minimum; // max ze vsech skupin

    ifstream t_soubor; // tady budu cist data ze souboru

public:
    Test();
    ~Test();
    void nactiData();
    void vypisVysledky();
    int pocetRadku(); // vraci pocet radku ve zdrojovem souboru
    int pocetVysledku(string & radek); // vraci pocet vysledku v jednom radku

    void pocitejStatistiku();
    void vypisStatistiku();

};

#endif // TEST_H
