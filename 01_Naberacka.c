#include <stdio.h>
#include <math.h>

float nactiVstup(){
	float polomer;
	int kontrola = 1;
	kontrola = scanf("%f", &polomer);
	printf("Zadejte polomer naberacky: ");

	while(kontrola < 1){
		while(getchar() != '\n'); // vycisteni vstupu
		printf("Spatny vstup, prosim zadejte znovu.\n");
		kontrola = scanf("%f", &polomer);
	}
	return polomer;
}

float objemNaberacky(float polomer){
	return (2.0/3.0)*3.1415*pow(polomer, 3);
}

int main(void){

	float polomer = nactiVstup();
	float vysledek = objemNaberacky(polomer);
	printf("Naberacka o polomeru %f ma objem %f", polomer, vysledek);

	return 0;
}