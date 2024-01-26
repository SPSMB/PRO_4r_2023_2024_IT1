#include "fronta.h"

Fronta::Fronta()
{
    // inicializace promennych
    f_prvni = NULL;
    f_posledni = NULL;
    f_citac = 0;
}

Osoba *Fronta::prvni()
{
    return f_prvni;
}

Osoba *Fronta::posledni()
{
    return f_posledni;
}

bool Fronta::je_Prazdna()
{
    // if(citac == 0)
    if(f_prvni == NULL && f_posledni == NULL){
        return true;
    } else {
        return false;
    }
}
