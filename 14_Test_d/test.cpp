#include "test.h"

Test::Test()
{
    t_pocSkupin = pocetRadku(); // zjistim pocet radku
    nactiData();
    t_minimum = 0;
    t_maximum = 10;
    t_celkovyPocet = 0;
    t_celkovySoucet = 0;
    t_cns = 0;
    // reset na vychozi hodnoty
    t_maximaVeskupinach.resize(t_pocSkupin, false);
    t_prumeryVeSkupinach.resize(t_pocSkupin, 0); // reset
}

Test::~Test()
{

}

void Test::nactiData()
{

    t_soubor.open("../vysledky-testu-b.txt");
    if(!t_soubor.is_open()){
        cout << "Chyba cteni souboru ve funkci nactiData.\n";
        return;
    }

    for(int i = 0; i < t_pocSkupin; i++){
        string radek = "";
        getline(t_soubor, radek);
        int pocet = pocetVysledku(radek); // Pocet vysledku v i-te skupine

        //t_ptvs.push_back(pocet);
        // 2. varianta
        t_ptvs.resize(t_pocSkupin);
        t_ptvs[i] = pocet;

        // naplnim pole hodnotami
        stringstream s(radek);
        vector<int> radekData;
        int tmp;
        for(int k=0; k<pocet; k++ ){
            s >> tmp;
            radekData.push_back(tmp);
        }
        t_vysledky.push_back(radekData);
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
            int h = t_vysledky[s][i]; // aktualni hodnota
            t_celkovySoucet += h;
            t_celkovyPocet++;
            t_prumeryVeSkupinach[s] += h; // prozatim tam ukladam soucty
            // pocitam prumery
            soucetRadku+=t_vysledky[s][i];
            // kontrola nalezeneho maxima
            if(h == t_maximum){
                t_maximaVeskupinach[s] = true;
            }
        }
        // ziskam spravny prumer ve skupine s indexem 's'
        // kontrolni vypisy
        cout << "Vypocet sk" << s << ": " << t_prumeryVeSkupinach[s] << "/" << (float) t_ptvs[s] << endl;
        t_prumeryVeSkupinach[s] = t_prumeryVeSkupinach[s] / (float) t_ptvs[s];

        // proverim, jestli jsme nahodou nasel nejlepsi skupinu
        if(t_prumeryVeSkupinach[s] > t_prumeryVeSkupinach[t_cns]){
            t_cns = s; // aktualni skupina je nejlepsi
        }
    }
    t_celkovyPrumer = t_celkovySoucet / (float) t_celkovyPocet;
}

void Test::vypisStatistiku()
{
    // Best Group - skupina s nejvyssim prumerem
    // tady bude nejak uzitecne t_cns
    cout << "Best Group - skupina s nejvyssim prumerem" << endl;
    cout << " je skupina s indexem " << t_cns << " - prumer je: "
         << t_prumeryVeSkupinach[t_cns] << endl;
    cout << "-----------------------------\n";

    // AvgAvg - prumery ve vsech skupinach
    cout << "AvgAvg - prumery ve vsech skupinach" << endl;
    for(int s = 0; s < t_pocSkupin; s++){
        cout << "Prumer skupiny " << s << ": " << t_prumeryVeSkupinach[s] << "\n";
    }
    cout << "Celkovy prumer ze vsech skupin: " << t_celkovyPrumer << endl;
    cout << "-----------------------------\n";

    // MaxScore - vsechny skupiny, kde nekdo dosahl maxima
    cout << "MaxScore - vsechny skupiny, kde nekdo dosahl maxima" << endl;
    for(int i=0; i<t_pocSkupin; i++){
        if(t_maximaVeskupinach[i]){
            cout << "Maximum dosazeno ve skupine " << i << ".\n";
        }
    }
    cout << "-----------------------------\n";
}
