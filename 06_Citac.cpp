#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Citac {
  protected:
	int c_hodnota;
	int c_pocHodnota;
  public:
	void zvetsit() {c_hodnota++;}
	void zmensit() {c_hodnota--;}
	void nastavit() { c_hodnota = c_pocHodnota;}
	int hodnota() {return c_hodnota;}
	void vypis() {cout << c_hodnota << endl; }
	Citac(int ph) {c_pocHodnota=ph; nastavit();}
};

class CitacMod1 : public Citac {
private:
	int c_modul;
public:
	// konstruktor
	CitacMod1(int ph, int modul) : Citac(ph%modul){
		c_modul = modul;
	}
	void zvetsit(){
		Citac::zvetsit();
		c_hodnota = c_hodnota % c_modul;
	}
	void zmensit(){
		Citac::zmensit();
		c_hodnota = c_hodnota % c_modul;
		if(c_hodnota < 0){
			c_hodnota = c_hodnota + c_modul;
		}
	}
};

class CitacMod2 : public Citac {
private:
	int c_modul;
public:
	// konstruktor
	CitacMod2(int ph, int modul) : Citac(ph%modul){
		c_modul = modul;
	}
	void zvetsit(){
		Citac::zvetsit();
		c_hodnota = c_hodnota % c_modul;
	}
	void zmensit(){
		Citac::zmensit();
		c_hodnota = c_hodnota % c_modul;
		if(c_hodnota < 0){
			c_hodnota = c_hodnota + c_modul;
		}
	}
};

class CitacD : public Citac {
public:
	// konstruktor
	CitacD(int ph) : Citac(ph){}

	void zvetsit(int kolik){
		c_hodnota += kolik;
	}
	void zmensit(int kolik){
		c_hodnota -= kolik;
	}
	void vypis(){
	 	cout << c_hodnota/24 << "dni a " << c_hodnota%24 << "hodin." << endl;
	}	
};

int main(){

/*
	CitacMod c1(3,4);

	c1.zvetsit();
	c1.zvetsit();
	c1.vypis();
	c1.zmensit();
	c1.zmensit();
	c1.vypis();
*/

/*
	Citac  x(0);  
	CitacMod1  x1(0,4); 
	CitacMod2  x2(0,5);

	Citac *p;  CitacMod1 *p1;  CitacMod2 *p2;

	x = x1; // OK    
	// x1 = x; // NE  
	p = p1; // OK   
	// p1 = p; // NE

	// x1 = x2; 	// NE
	x = x2; 	// OK
	// p1 = p2; 	// NE
	p = p2; 	// OK
*/

	CitacD d(40);

	d.zvetsit(30);
	d.zmensit(10);
	d.vypis();

	return 0;
}