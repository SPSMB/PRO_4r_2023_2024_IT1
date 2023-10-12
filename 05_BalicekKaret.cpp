#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class BalicekKaret {
private:

	int b_vrchol;
	int b_dno;
	int b_limit;
	char b_balicek[1000];

public:
	BalicekKaret();
	/*~BalicekKaret();*/
	void vlozNaVrchol(char karta);
	void odeberZVrcholu();
	void odeberZeDna();
	void vypisBalicek();
};

BalicekKaret::BalicekKaret(){
	b_dno = -1;
	b_vrchol = -1;
	b_limit = 1000;
}

void BalicekKaret::vypisBalicek(){
	for(int i = b_dno; i<= b_vrchol; i++){
		cout << b_balicek[i] << " ";
	}
	cout << endl;
}

void BalicekKaret::vlozNaVrchol(char karta){
	if(b_vrchol == b_limit -1){
		cout << "Balicek je plny, nelze vlozit." << endl;
	} else {
		b_balicek[++b_vrchol] = karta;
	}
}

void BalicekKaret::odeberZVrcholu(){
	if(b_vrchol == -1){
		cout << "Nejde odebrat" << endl;
	} else {
		b_balicek[b_vrchol] = ' ';
		b_vrchol--;
		// balicek je prazdny -> reset
		if(b_dno > b_vrchol){
			b_dno = b_vrchol = -1;
		}
	}
}

void BalicekKaret::odeberZeDna(){
	if(b_dno == -1){
		cout << "Nelze z prazdneho balicku odebrat.\n";
	} else {
		b_balicek[b_dno] = ' ';
		b_dno++;
		// balicek je prazdny -> reset
		if(b_dno > b_vrchol){
			b_dno = b_vrchol = -1;
		}	
	} 
}

int main(){

	BalicekKaret b;
	b.vlozNaVrchol('2');
	b.vlozNaVrchol('5');
	b.vlozNaVrchol('7');
	b.vlozNaVrchol('A');
	b.vypisBalicek();

	b.odeberZVrcholu();
	b.odeberZVrcholu();
	b.vypisBalicek();

	b.vlozNaVrchol('Q');
	b.vlozNaVrchol('9');
	b.vypisBalicek();

	b.odeberZeDna();
	b.vypisBalicek();

	return 0;
}