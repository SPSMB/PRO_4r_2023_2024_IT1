#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// obsah stringstreamu s1 zapise do souboru nazevSouboru
// vraci true, kdyz uspech
// vraci false, kdyz neuspech
bool zapisDoSouboru(string nazevSouboru, stringstream & s1){
	ofstream f2;
	f2.open(nazevSouboru);
	if(!f2.is_open()){
		cout << "Nebylo mozne otevrit soubor pro zapis.\n";
		return false;
	}
	f2 << s1.str(); // cely obsah streamu ulozim do f2
	f2.close();
	return true;
}

/* vraci 1 v pripade neuspechu, jinak 0 */
int nactiStanice(string & nazevSouboru, stringstream & s1){
	system("chcp 65001");

	string radek;
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
			s1 << druhy << "(" << prvni << ")" << endl;
			prahaCitac++;
		}
	}
	f.close();

	cout << "Nacteno " << citac << " stanic." << endl;
	cout << "  z toho " << prahaCitac << " stanic je v Praze." << endl;
	return 0;
}

int main()
{
	stringstream s1;
	string nazevSouboruOUT = "vlaky.txt";
	string nazevSouboruIN = "Stanice_slovnik_2023.csv";
	nactiStanice(nazevSouboruIN, s1);
	zapisDoSouboru(nazevSouboruOUT, s1);

	return 0;
}