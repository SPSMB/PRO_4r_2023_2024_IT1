#include "linka.h"

// konstruktor
Linka::Linka()
{
    l_posledni = NULL;
}

void Linka::vypisStanice()
{
    if(l_posledni != NULL){
        int citac = 1;
        // ukazatel na prvni stanici
        Stanice * tmp = l_posledni->dalsi;

        do{
            cout << citac << ": " << tmp->jmeno.toStdString() << endl;
            tmp = tmp->dalsi;
            citac++;
        }while(tmp != l_posledni->dalsi);
    } else {
        cout << "Seznam stanic je prazdny.\n";
    }
}

void Linka::vlozStanici(QString jmeno)
{
    Stanice * st = new Stanice();
    st->jmeno = jmeno;
    if(l_posledni == NULL){
        // seznam je zatim prazdny
        l_posledni = st;
        st->dalsi = st;
        st->predchozi = st;
    } else {
        st->dalsi = l_posledni->dalsi;
        st->predchozi = l_posledni;
        l_posledni->dalsi->predchozi = st;
        l_posledni->dalsi = st;
        l_posledni = st;
    }
}

Stanice * Linka::odeberStanici(Stanice *st)
{
    if(l_posledni == NULL){
        cout << "Neni co odebrat z prazdneho seznamu.\n";
        return NULL;
    } else {
        // kdyz mam jenom jednu stanici
        if(st->dalsi == st){
            l_posledni = NULL;
            cout << "Odebiram stanici " << st->jmeno.toStdString() << ".\n"; // pomocny vypis
            delete st;
            return l_posledni;
        } else { // kdyz mam 2 a vice stanic
            if(l_posledni == st){
                l_posledni = st->predchozi;
            }
            st->dalsi->predchozi = st->predchozi;
            st->predchozi->dalsi = st->dalsi;
            cout << "Odebiram stanici " << st->jmeno.toStdString() << ".\n"; // pomocny vypis
            delete st;
            return l_posledni;
        }
    }
}

void Linka::smazPosledni()
{
    odeberStanici(l_posledni);
}

void Linka::smazVse()
{
    Stanice * tmp = l_posledni;
    while(tmp!=NULL){
        tmp = odeberStanici(tmp);
    }
}
