#include <iostream>
#include <string>
#include "morseovka.h"

using namespace std;

int main()
{
    string vstup;
    string vystup;
    Morseovka m;

    cout << "Prosim zadejte text v morseovce, 0 pro ukonceni programu\n";

    while(true){
        cin >> vstup;
        if(vstup == "0"){
            break;
        }
        m.dekoduj(vstup, vystup);
        cout << vystup << endl;
        vstup = vystup = "";
    }

    return 0;
}
