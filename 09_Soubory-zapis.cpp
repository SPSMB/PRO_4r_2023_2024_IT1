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

int main()
{
	string nazevSouboru("soubor1.txt");
	stringstream s1;


	for(int i=0; i<1000; i++){
		s1 << "FUNKCE-I: " << i << endl;
		// pri prekroceni limitu se s1 resetuje
		if(i==500) s1.str("");
	}

	zapisDoSouboru(nazevSouboru, s1);

	return 0;
}