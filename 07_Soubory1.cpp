#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	
	string jmenosouboru = "soubor1.txt";
	string slovo;
	string radek;
	ifstream f1;
	f1.open(jmenosouboru);

	if(!f1.is_open()){
		cout << "Chyba, soubor " << jmenosouboru << " se nepovedlo otevrit." << endl;
		return 1;
	}

	// varianta 1 - po slovech
	/*
	while(f1 >> slovo){
		cout << ">" << slovo << "<" << endl;
	}
	*/

	// varianta 2 - po radcich
	while(getline(f1, radek)){
		cout << ">" << radek << "<" << endl;
	}

	f1.close();

	return 0;
}