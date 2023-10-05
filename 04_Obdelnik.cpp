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

	bool jeUvnitr(int x, int y);
	bool jeCtverec();
	void vypis();
};
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
	cout << "vola se konstruktor se 4 parametry" << endl;
}

Obdelnik::Obdelnik(void){
	o_sirka = o_vyska = o_ax = o_ay = 2;
	cout << "vola se konstruktor bez parametru" << endl;
}

Obdelnik::~Obdelnik(){
	cout << "Konec objektu" << endl;
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
	*vystup_x = vstup_x*cos(alphaRad) - vstup_y*sin(alphaRad);
	*vystup_y = vstup_x*sin(alphaRad) + vstup_y*cos(alphaRad);
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
void Obdelnik::otoc(int x, int y, int alpha){
	
	int ax = o_ax;
	int ay = o_ay;
	int bx = o_ax + o_sirka;
	int by = o_ay + o_vyska;

	// 1) transformace
	transformace(ax, ay, &ax, &ay, x, y);
	transformace(bx, by, &bx, &by, x, y);

	// 2) otoceni
	otocPodleStredu(ax, ay, &ax, &ay, alpha);
	otocPodleStredu(bx, by, &bx, &by, alpha);
	
	// 3) zpetna transformace
	zpetnatransformace(ax, ay, &ax, &ay, x, y);
	zpetnatransformace(bx, by, &bx, &by, x, y);
	
	// 4) normalizace
	normalizace(ax, ay, bx, by);
	// srovnam sirku a vysku
	if(alpha == 90 || alpha == -90){
		int tmpSirka;
		tmpSirka = o_sirka;
		o_sirka = o_vyska;
		o_vyska = tmpSirka; 
	}
}

bool Obdelnik::jeUvnitr(int x, int y){
	if(  o_ax <= x && x <= o_ax + o_sirka &&
		 o_ay <= y && y <= o_ay + o_vyska){
		return true;
	} else {
		return false;
	}
}

bool Obdelnik::jeCtverec(){
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

int main(){

	Obdelnik o1(2,3,4,2);
	o1.vypis();
	o1.otoc(4,6,180);
	o1.vypis();

	Obdelnik o2;
	o2.vypis();

	// dynamicky
	Obdelnik * o3 = new Obdelnik(10,10,1,1);
	o3->vypis();
	

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