#include "test.h"

Test::Test()
{
    //cout << "Kolik bude skupin?";
    t_soubor.open("../vysledky-testu-a.txt");
    if(! t_soubor.is_open()){
       cout << "Soubor se nepovedlo otevrit.\n";
       return;
    }
    t_soubor >> t_pocSkupin;
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
    for(int i = 0; i < t_pocSkupin; i++){
        //cout << "Kolik je vysledku v " << i << ". skupine? ";
        int pocet; // pocet testu v aktualni skupine
        t_soubor >> pocet;
        t_vysledky[i] = new int[pocet];
        t_ptvs[i] =pocet;

        //cout << "Nyni zadejte vysledky ve skupine " << i << " oddelene mezerami" << endl;
        // naplnim pole hodnotami
        for(int k=0; k<pocet; k++ ){
            t_soubor >> t_vysledky[i][k];
        }
    }
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
