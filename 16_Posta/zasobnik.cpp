#include "zasobnik.h"

Zasobnik::Zasobnik()
{

    z_ukazatel = 0; // ukazuje na prvni volne misto = prvni volny index v poli
    z_pocatecniKapacita = 10; // kolik se vejde prvku na zacatku
    z_kapacita = z_pocatecniKapacita;

    z_poleOsob = new Osoba * [z_kapacita];

}

Zasobnik::~Zasobnik()
{
    int pocet = 0;
    for(int i = z_ukazatel-1 ; i>=0; i-- ){
        pocet++;
        Osoba * os = pop();
        delete os;
    }
    qDebug() << "Destruktor Zasobnik: Odebrano " << pocet << " osob.";
    delete [] z_poleOsob;
}

void Zasobnik::push(Osoba *os)
{
    if(os == NULL){
        qDebug() << "Push: Nelze vlozit do zasobniku prazdny ukazatel.";
    } else {
        // jeste nez pridam do pole, musim zkontrolovat kapacitu
        kontrolujKapacitu();
        z_poleOsob[z_ukazatel] = os;
        z_ukazatel++;
        top(); // kontrolni vypis
    }
}

Osoba * Zasobnik::pop()
{
    if(is_empty()){
        qDebug() << "Pop: Zasobnik je prazdny, nelze nic odebrat.";
        return NULL;
    }
    z_ukazatel--; // snizim ukazatel
    Osoba * os = z_poleOsob[z_ukazatel];
    top(); // vypisuje, kdo je zrovna na vrcholu zasobniku
    kontrolujKapacitu(); // zmensi pole, pokud mame prilis malo prvku
    return os;
}

void Zasobnik::top()
{
    if(is_empty()){
        qDebug() << "Top: Zasobnik je prazdny.";
    } else {
        Osoba * os = z_poleOsob[z_ukazatel-1];
        qDebug() << "Top: " << os->id << ": " << os->jmeno;
    }
}

bool Zasobnik::is_empty()
{
    if(z_ukazatel == 0){
        return true;
    } else {
        return false;
    }
}

QString Zasobnik::toString()
{
    QString vystup = "";
    // for(auto & os : z_poleOsob ){
    for(int i = z_ukazatel-1; i>=0 ; i--){
        Osoba * os = z_poleOsob[i];
        vystup += QString::number(os->id) + ": " + os->jmeno + "\n";
    }
    return vystup;
}

void Zasobnik::kontrolujKapacitu()
{
    // pri zaplneni vetsim nez 90%
    if(z_ukazatel >= z_kapacita*0.9){
        // zvetsi pole
        zmenPole(true);
    // pri zaplneni mensim nez 40%
    } else if (z_ukazatel < z_kapacita*0.4 && z_kapacita > z_pocatecniKapacita){
        // zmensi pole
        zmenPole(false);
    }
}

void Zasobnik::zmenPole(bool zvetsit)
{
    int nova_kapacita;
    if(zvetsit){
        nova_kapacita = z_kapacita * 2;
    } else {
        nova_kapacita = z_kapacita / 2;
    }

    qDebug() << "Alokuji pole - puvodni kapacita: " << z_kapacita
             << ", nova kapacita: " << nova_kapacita;

    // 1. alokace noveho pole
    Osoba * * pole2 = new Osoba*[nova_kapacita];

    // 2. kopiruji prvky ze stareho pole do noveho
    for(int i=0; i < z_ukazatel; i++){
        pole2[i] = z_poleOsob[i];
    }

    // 3. mazu stare pole
    delete [] z_poleOsob;

    // 4. presunu ukazatel
    z_poleOsob = pole2;

    // nastavim novou kapacitu
    z_kapacita = nova_kapacita;
}
