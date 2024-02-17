#include "fronta.h"
#include <QDebug>

Fronta::Fronta()
{
    // inicializace promennych
    f_prvni = NULL;
    f_posledni = NULL;
    f_citac = 0;
}

Fronta::~Fronta()
{
    qDebug() << "Vola se destruktor";
    Osoba * os;
    int pocet = 0;
    while(!je_Prazdna()){
        os = this->odeber();
        pocet++;
        delete os;
    }
    qDebug() << "Destruktor Fronta: Odebrano " << pocet << " osob.";
}

// osoba uz existuje a dostanu na ni ukazatel os
void Fronta::pridej(Osoba *os)
{
    if(je_Prazdna()){
        f_prvni = os;
        f_posledni = os;
    } else {
        f_posledni->dalsi = os;
        f_posledni = os;
    }
    os->dalsi = NULL;
    f_citac++;
    os->id = f_citac;
    prvni();
    posledni();
}

// vraci ukazatel na osobu, pokud neni co odebrat, vraci NULL
Osoba * Fronta::odeber()
{
    if(je_Prazdna()){
        qDebug() << "Fronta je prazdna, nelze odebirat." << endl;
        return NULL;
    } else {
        Osoba * os = f_prvni;
        if(f_prvni == f_posledni){
            f_posledni = NULL;
        }
        // f_citac--; // nechceme, aby se citac snizoval
        f_prvni = f_prvni->dalsi;
        return os;
    }
    prvni();
    posledni();
}

Osoba * Fronta::prvni()
{
    if(je_Prazdna()){
        qDebug() << "Fronta je prazdna." << endl;
    } else {
        qDebug() << "Prvni: " << f_prvni->id << ": " << f_prvni->jmeno;
    }
    return f_prvni;
}

Osoba * Fronta::posledni()
{
    if(je_Prazdna()){
        qDebug() << "Fronta je prazdna." << endl;
    } else {
        qDebug() << "Posledni: " << f_posledni->id << ": " << f_posledni->jmeno;
    }
    return f_posledni;
}

bool Fronta::je_Prazdna()
{
    // if(citac == 0) // toto uz nejde pouzit
    if(f_prvni == NULL && f_posledni == NULL){
        return true;
    } else {
        return false;
    }
}

QString Fronta::toString()
{
    QString vystup = "";
    Osoba * os = f_prvni;
    while (os != NULL) {
        vystup += QString::number(os->id) + ":" + os->jmeno + '\n';
        qDebug() << vystup;
        os = os->dalsi;
    }
    return vystup;
}
