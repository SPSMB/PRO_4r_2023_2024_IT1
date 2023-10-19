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
	Citac(int ph) {c_pocHodnota=ph; nastavit();}
};

class CitacMod : public Citac {

};


int main(){


	return 0;
}