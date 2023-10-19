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
	bool jePrazdny();
};

BalicekKaret::BalicekKaret(){
	b_dno = -1;
	b_vrchol = -1;
	b_limit = 1000;
}

bool BalicekKaret::jePrazdny(){
	if(b_dno == b_vrchol && b_dno == -1){
		return true;
	} else {
		return false;
	}
}

void BalicekKaret::vypisBalicek(){
	if(jePrazdny()){
		cout << "Balicek je prazdny" << endl;
	} else {
		for(int i = b_dno; i<= b_vrchol; i++){
			cout << b_balicek[i] << " ";
		}
		cout << endl;	
	}
}

void BalicekKaret::vlozNaVrchol(char karta){
	if(jePrazdny()){
		b_dno++;
	}
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
		// balicek se prave vyprazdnil -> reset
		if(b_dno > b_vrchol){
			b_dno = b_vrchol = -1;
		}
	}
}

void BalicekKaret::odeberZeDna(){
	cout << "[Odeber]: b_dno: " << b_dno << ", b_vrchol: " << b_vrchol << endl;
	if(b_dno == -1){
		cout << "Nelze z prazdneho balicku odebrat.\n";
	} else {
		b_balicek[b_dno] = ' ';
		b_dno++;
		// balicek se prave vyprazdnil -> reset
		if(b_dno > b_vrchol){
			b_dno = b_vrchol = -1;
		}	
	} 
}

int main(){

	BalicekKaret b;
	b.vypisBalicek();
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

	b.odeberZeDna();
	b.odeberZeDna();
	b.vypisBalicek();
	b.odeberZeDna();
	b.vypisBalicek();

	b.vlozNaVrchol('K');
	b.odeberZeDna();
	b.vypisBalicek();

	return 0;
}