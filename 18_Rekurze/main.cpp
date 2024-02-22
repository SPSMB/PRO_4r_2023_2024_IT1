#include <iostream>

using namespace std;

int faktorial_I(int x){

    int vysledek = 1;
    for(int i = 1; i<=x; i++){
        vysledek *= i;
    }
    return vysledek;
}

int faktorial_R(int x){
    if(x == 0 || x == 1){
        return 1;
    } else {
        return x * faktorial_R(x-1);
    }
}

void vypocetfaktorialu(){

    int x;
    cout << "Zadejte cislo: ";
    cin >> x;
    // 1 - iterativne
    cout << "Vysledek iterativne: " << faktorial_I(x) << endl;

    // 2 - rekurzivne
    cout << "Vysledek rekurzivne: " << faktorial_R(x) << endl;

}

int main()
{
    // 1 vypocet faktorialu
    vypocetfaktorialu();

    return 0;
}
