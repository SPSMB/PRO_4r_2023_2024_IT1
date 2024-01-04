#include "test.h"

Test::Test()
{
    t_pocSkupin = pocetRadku(); // zjistim pocet radku
    // cout << "Pocet radku: " << t_pocSkupin << endl;
    t_ptvs = new int[t_pocSkupin]; // dynamicka alokace
    t_souctyVeSkupinach = new int[t_pocSkupin]; // dynamicka alokace
    t_prumeryVeSkupinach = new int[t_pocSkupin]; // dynamicka alokace
    nactiData();
}

Test::~Test()
{
    for(int i=0; i<t_pocSkupin; i++){
        delete [] t_vysledky[i];
    }
    delete [] t_vysledky;
    delete [] t_ptvs;
    delete [] t_souctyVeSkupinach;
    delete [] t_prumeryVeSkupinach;
}

void Test::nactiData()
{
    // alokace 2D pole
    t_vysledky = new int*[t_pocSkupin];

    t_soubor.open("../vysledky-testu-b.txt");
    if(!t_soubor.is_open()){
        cout << "Chyba cteni souboru ve funkci nactiData.\n";
        return;
    }

    for(int i = 0; i < t_pocSkupin; i++){
        string radek = "";
        getline(t_soubor, radek);
        int pocet = pocetVysledku(radek); // Pocet vysledku v i-te skupine

        t_vysledky[i] = new int[pocet]; // alokace pameti
        t_ptvs[i] =pocet;

        // naplnim pole hodnotami
        stringstream s(radek);
        for(int k=0; k<pocet; k++ ){
            s >> t_vysledky[i][k];
        }
    }
    t_soubor.close();
}

void Test::vypisVysledky()
{
    cout << "--------------------\n";
    cout << "Vysledky ve vsech skupinach: " << endl;
    for(int r = 0; r < t_pocSkupin; r++){
        cout << "Skupina " << r << ": ";
        for(int s = 0; s < t_ptvs[r]; s++){
            cout << t_vysledky[r][s] << " ";
        }
        cout << endl;
    }
}

int Test::pocetRadku()
{
    int pocet = 0;
    t_soubor.open("../vysledky-testu-b.txt");
    if(t_soubor.is_open()){
        string radek;
        while(getline(t_soubor, radek)){
            pocet++;
        }
    } else {
        cout << "Chyba pri cteni souboru ve funkci pocetRadku.\n";
    }
    t_soubor.close();
    return pocet;
}

int Test::pocetVysledku(string &radek)
{
    int pocet = 0;
    int tmp; // pomocna promenna, hodnoty nas nezajimaji, jen jejich pocet
    stringstream s(radek);
    while( s >> tmp ){
        pocet++;
    }
    return pocet;
}

void Test::pocitejStatistiku()
{
    for (int s=0; s < t_pocSkupin; s++) {
        int soucetRadku = 0;
        for (int i=0; i<t_ptvs[s]; i++) {
            // pocitam prumery
            soucetRadku+=t_vysledky[s][i];
        }

    }
}
