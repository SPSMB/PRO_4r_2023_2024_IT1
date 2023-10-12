#include <string>
#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

class Obdelnik {
private:
	int o_ax; // levy dolni roh
	int o_ay; // levy dolni roh
	int o_vyska;
	int o_sirka;
	static int o_pocet;

public:

	/*Obdelnik();*/
	Obdelnik(int x, int y, int sirka, int vyska);
	Obdelnik(void);
	~Obdelnik();
	int sirka(){
		return o_sirka;
	}
	void nastavRozmery(int x, int y){
		o_ax = x;
		o_ay = y;
	}
	void otoc(int x, int y, int alpha);
	void transformace(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int s_x, int s_y);
	void otocPodleStredu(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int alpha);
	void zpetnatransformace(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int s_x, int s_y);
	void normalizace(int a_x, int a_y, int b_x, int b_y);

	bool jeUvnitr(int x, int y) const;
	bool jeCtverec() const;
	void vypis();
	static int kolik();
};

int Obdelnik::o_pocet = 0;
/*
Obdelnik::Obdelnik(){
	o_x = 0;
	o_y = 0;
	o_sirka = 0;
	o_vyska = 0;
}
*/
Obdelnik::Obdelnik(int x, int y, int sirka, int vyska){
	o_ax = x;
	o_ay = y;
	o_sirka = sirka;
	o_vyska = vyska;
	o_pocet++;
	cout << "vola se konstruktor se 4 parametry, "
		 << "pocet: " << o_pocet << endl;
}

Obdelnik::Obdelnik(void){
	o_sirka = o_vyska = o_ax = o_ay = 2;
	o_pocet++;
	cout << "Vola se konstruktor bez parametru, pocet: "
		 << o_pocet << endl;
}

Obdelnik::~Obdelnik(){
	o_pocet--;
	cout << "Konec objektu, aktualni pocet obdelniku: " 
		 << o_pocet << endl;
}

void Obdelnik::transformace(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int s_x, int s_y){
	*vystup_x = vstup_x - s_x;
	*vystup_y = vstup_y - s_y;
}

void Obdelnik::zpetnatransformace(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int s_x, int s_y){
	*vystup_x = vstup_x + s_x;
	*vystup_y = vstup_y + s_y;
}

void Obdelnik::otocPodleStredu(int vstup_x, int vstup_y, int * vystup_x, int * vystup_y, int alpha){
	double pi = 2*acos(0.0);
	double alphaRad = alpha*(pi/180.0);

	//cout << "Otaceni: Mx1:" << vstup_x*(int)cos(alphaRad) 
	//	 << ", Mx2: " << vstup_y*(int)sin(alphaRad) << endl;
	//cout << "Otaceni: My1:" << vstup_x*(int)sin(alphaRad) 
	//	 << ", My2: " << vstup_y*(int)cos(alphaRad) << endl;
	
	*vystup_x = vstup_x*(int)cos(alphaRad) - vstup_y*(int)sin(alphaRad);
	*vystup_y = vstup_x*(int)sin(alphaRad) + vstup_y*(int)cos(alphaRad);
}

void Obdelnik::normalizace(int a_x, int a_y, int b_x, int b_y){
	if(a_x < b_x){
		o_ax = a_x;
	} else {
		o_ax = b_x;
	}
	if(a_y < b_y){
		o_ay = a_y;
	} else {
		o_ay = b_y;
	}
}

// otoci obdelnik podle libovolneho stredu o 90,-90,180 stupnu
void Obdelnik::otoc(int sx, int sy, int alpha){
	
	int ax = o_ax;
	int ay = o_ay;
	int bx = o_ax + o_sirka;
	int by = o_ay + o_vyska;

	// 1) transformace
	transformace(ax, ay, &ax, &ay, sx, sy);
	transformace(bx, by, &bx, &by, sx, sy);

	//cout << "1) Po transformaci: A[" << ax << ";" << ay << "] B[" << bx << ";" << by << "]\n";

	// 2) otoceni
	otocPodleStredu(ax, ay, &ax, &ay, alpha);
	otocPodleStredu(bx, by, &bx, &by, alpha);

	//cout << "2) Po otoceni: A[" << ax << ";" << ay << "] B[" << bx << ";" << by << "]\n";
	
	// 3) zpetna transformace
	zpetnatransformace(ax, ay, &ax, &ay, sx, sy);
	zpetnatransformace(bx, by, &bx, &by, sx, sy);

	//cout << "3) Po zpetne transformaci: A[" << ax << ";" << ay << "] B[" << bx << ";" << by << "]\n";
	
	// 4) normalizace
	normalizace(ax, ay, bx, by);

	//cout << "4) Po normalizaci: A[" << o_ax << ";" << o_ay << "]\n";
	// srovnam sirku a vysku
	if(alpha == 90 || alpha == -90){
		int tmpSirka;
		tmpSirka = o_sirka;
		o_sirka = o_vyska;
		o_vyska = tmpSirka; 
	}
}

bool Obdelnik::jeUvnitr(int x, int y) const{
	if(  o_ax <= x && x <= o_ax + o_sirka &&
		 o_ay <= y && y <= o_ay + o_vyska){
		return true;
	} else {
		return false;
	}
}

 bool Obdelnik::jeCtverec() const{
	if(o_vyska == o_sirka){
		return true;
	} else {
		return false;
	}
}

void Obdelnik::vypis(){
	cout << "Obdelnik na souradnicich [" << o_ax << "," << o_ay 
	<< "] sirka:" << o_sirka << ", vyska:" << o_vyska << endl;
}

int Obdelnik::kolik(){
	cout << "Kolik: Prave existuje " << o_pocet << " obdelniku.\n";
	return o_pocet;
}

int main(){

	Obdelnik o1(2,3,4,2);
	o1.vypis();
	o1.otoc(4,6,90);
	o1.vypis();

	Obdelnik * o4 = new Obdelnik();
	Obdelnik::kolik();

	Obdelnik o2(3,4,5,6);
	o2.vypis();
	delete o4;
	Obdelnik o3(7,8,9,10);
	o3.vypis();

	//Obdelnik o2;
	//o2.vypis();

	// dynamicky
	//Obdelnik * o3 = new Obdelnik(10,10,1,1);
	//o3->vypis();
	

/*
	silnice2.vypis();
	if(silnice2.jeCtverec()){
		cout << "je ctverec" << endl;
	} else {
		cout << "neni ctverec" << endl;
	}

	if(silnice2.jeUvnitr(-3,24)){
		cout << "Bod je uvnitr\n";
	} else {
		cout << "Bod je venku\n";
	}
*/

	return 0;
}