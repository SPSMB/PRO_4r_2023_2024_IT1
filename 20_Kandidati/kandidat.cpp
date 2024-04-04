#include "kandidat.h"

Kandidat::Kandidat(QString jmeno, QString prijmeni, int narozen, QString foto)
{
    k_jmeno = jmeno;
    k_prijmeni = prijmeni;
    k_narozen = narozen;
    this->setText(toString());
    k_foto = foto;

    k_stav = "novy";
    k_posledniZmena = QDateTime::currentDateTime();
}

QString Kandidat::toString()
{
    QString vystup = k_jmeno + " " + k_prijmeni + " ("
                             + QString::number(vek()) + " let)";

    return vystup;
}

QString Kandidat::stav()
{
    return k_stav;
}

void Kandidat::posunStav(bool rozhodnuti)
{
    k_posledniZmena = QDateTime::currentDateTime();
    if(rozhodnuti == false){
        k_stav = "zamitnut";
        return;
    }

    // rozhodnuti == true
    if(k_stav == "novy"){
        k_stav = "schvalen";
    } else if(k_stav == "schvalen"){
        k_stav = "prijat";
    }

}

int Kandidat::vek()
{
    //int aktualni_rok = QDateTime::currentDateTime().date().year();

    //int aktualni_mesic = QDate::currentDate().month();
    //int aktualni_den = QDate::currentDate().day();

    QDate datum = QDate::currentDate();
    qDebug() << datum.toString("dd.MM.yyyy");

    int aktualni_rok = QDate::currentDate().year();
    return aktualni_rok - k_narozen;
}
