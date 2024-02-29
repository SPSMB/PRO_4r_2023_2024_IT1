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


int fibonacci_R(int x){
    if(x<=1){
        return 1;
    }
    else{
        return fibonacci_R(x-1) + fibonacci_R(x-2);
    }
}

int fibonacci_I(int x){
    int fibonacciMinusDva = 1;
    int fibonacciMinusJedna = 1;
    int fibonacciN = 2;
    if (x == 0 || x == 1){
        return 1;
    }
    if (x == 2) {
        return 2;
    }
    for (int i = 3; i <= x; i++) {
        fibonacciMinusDva = fibonacciMinusJedna;
        fibonacciMinusJedna = fibonacciN;
        fibonacciN = fibonacciMinusDva + fibonacciMinusJedna;
    }
    return fibonacciN;

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

void vypocetFibonaccihoCisla(){
    // 2 vypocet fibonacciho cisla
    int x = 0;
    while(x >= 0){
        cout << "Fib - jake cislo? ";
        cin >> x;
        //int vystup_R = fibonacci_R(x);
        int vystup_I = fibonacci_I(x);
        //cout << "Vystup rekurentne: " << vystup_R << endl;
        cout << "Vystup iterativne: " << vystup_I << endl;
   }
}

void obrat(){
    int x;
    cin >> x;
    if(x != 0){
        obrat();
    }
    if(x == 0) return;
    cout << x << " ";
}

void obraceniPosloupnosti(){
    cout << "Zadejte posloupnost zakoncenou nulou: ";
    obrat();
    cout << endl;
}

int main()
{
    // 1 vypocet faktorialu
    // vypocetfaktorialu();

    // 2 vypocet fibonacciho cisla
    // vypocetFibonaccihoCisla();

    // 3 obraceni posloupnosti
    obraceniPosloupnosti();

    return 0;
}
