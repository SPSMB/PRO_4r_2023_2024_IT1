#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	
	system("chcp 65001");

	string radek;
	string nazevSouboru = "Stanice_slovnik_2023.csv";
	int citac = 0;
	int prahaCitac = 0;

	ifstream f(nazevSouboru, ifstream::in);
	if(!f.is_open()){
		cout << "Nepovedlo sse otevrit soubor " << nazevSouboru << endl;
		return 1;
	}
	while(getline(f, radek)){
		if(radek.empty()) continue; //  radek.empty() radek == ""
		citac++;
		if(radek.find("Praha") != string::npos){
			string prvni = radek.substr(0,5);
			string druhy = radek.substr(6,radek.length()-1);
			cout << druhy << "(" << prvni << ")" << endl;
			prahaCitac++;
		}
	}
	f.close();

	cout << "Nacteno " << citac << " stanic." << endl;
	cout << "  z toho " << prahaCitac << " stanic je v Praze." << endl;

	return 0;
}