#include <iostream>
#include <QString>
#include <linka.h>
#include <QTextStream>

using namespace std;

int main()
{
    QTextStream qtin(stdin);
    Linka l; // zalozim linku l
    //system("chcp 65001");
    int volba = -1;
    // nekonecny cyklus
    while(1){
        cout << "Zadejte pokyn: -1:konec, 0:vloz, 1:vypis, 2:smaz vse,\n 3:smaz posledni 4:vypis od stanic 5:smaz stanici\n>";
        cin >> volba;
        while(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Toto neni povoleny vstup. Zadejte znovu.\n";
            cin >> volba;
        }

        if(volba == -1) break;
        if(volba == 0){
            QString jmeno;
            cout << "0: Zadejte jmeno stanice: ";
            qtin >> jmeno;
            l.vlozStanici(jmeno);
        } else if (volba == 1){
            l.vypisStanice(); // vypisu vsechny stanice
        } else if (volba == 2){
            l.smazVse();
        } else if(volba == 3){
            l.smazPosledni();
        } else if(volba == 4)
        {
            QString jmeno;
            cout << "4: Zadejte jmeno stanice: ";
            qtin >> jmeno;
            l.vypisStanice(jmeno);
        } else if(volba == 5)
        {
            QString jmeno;
            cout << "5: Zadejte jmeno stanice: ";
            qtin >> jmeno;
            l.odeberStanici(jmeno);
        } else {
            // Zahodim neuzitecny vstup
            cout << "Povoleny vstup je jen -1 - 5\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

}
