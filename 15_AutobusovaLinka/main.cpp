#include <iostream>
#include <QString>
#include <linka.h>
#include <QTextStream>

using namespace std;

int main()
{
    QTextStream qtin(stdin);
    Linka l; // zalozim linku l

    int volba = -1;
    // nekonecny cyklus
    while(1){
        cout << "Zadejte pokyn: -1:konec, 0:vloz, 1:vypis, 2:smaz, 3:smaz posledni\n>";
        cin >> volba;
        if(volba == -1) break;
        if(volba == 0){
            QString jmeno;
            cout << "Zadejte jmeno stanice: ";
            qtin >> jmeno;
            l.vlozStanici(jmeno);
        } else if (volba == 1){
            l.vypisStanice(); // vypisu vsechny stanice
        } else if (volba == 2){
            l.smazVse();
        } else if(volba == 3){
            l.smazPosledni();
        }
    }

}
