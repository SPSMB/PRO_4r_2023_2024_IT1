#include <stdio.h>
#define DELKAPOLE 50

/* 0) vytvorit strukturu pro 1 pivo */
typedef struct pivo {
	char nazev[30]; 
	float alkohol;
	float objem;
	float cena;
} Pivo;

int nactiInt(){
	int pocet;
	int kontrola = scanf("%d", &pocet);

	while (kontrola != 1)
	{
		printf("Spatne zadani.\n");
		printf("Zadejte pocet piv znovu:\n");
		while(getchar() != '\n'); /* odstranime spatne vstupy z vstupniho zasobniku */
		kontrola = scanf("%d", &pocet);
	}
	return pocet;
}

void nactiData(Pivo * basaPiv, int pocet){
	for(int i = 0; i < pocet; i++){
		while(getchar() != '\n');
		printf("%d. Zadejte nazev piva: ", i+1);
		scanf("%[^\n]%*c", basaPiv[i].nazev);
		int kontrola = -1;
		do{
			if(kontrola != -1) {
				while(getchar() != '\n');
				printf("Chybne zadani, prosim znovu.\n");
			}
			if(kontrola != 3){
				printf("   Zadejte alkohol, cenu a objem: ");
				kontrola = scanf("%f %f %f", 
					&(basaPiv[i].alkohol), 
					&basaPiv[i].cena, 
					&basaPiv[i].objem);
			}
		} while (kontrola != 3);
	}
}

/* kdyz bude nealko == 1, tak vypise jen nealko */
void vypisBasu(Pivo * basaPiv, int pocet, int nealko){
	printf("ID Nazev                Alkohol Cena Objem\n");
	for (int i = 0; i < pocet; i++)
	{
		if(nealko != 1 || (nealko == 1 && basaPiv[i].alkohol <= 0.5)){
			printf("%2d %-20s %7.2f %5.2f %5.2f\n", 
				i, 
				basaPiv[i].nazev, 
				basaPiv[i].alkohol,
				basaPiv[i].cena,
				basaPiv[i].objem
				);
		}
	}
}

void prumerCenaNealko(Pivo * basaPiv, int pocet){
	float soucet = 0;
	int pocetNealko = 0;
	for (int i = 0; i < pocet; i++){
		if(basaPiv[i].alkohol <= 0.5){
			soucet += basaPiv[i].cena / basaPiv[i].objem;
			pocetNealko++;
		}
	}

	float prumer = soucet/pocetNealko;
	printf("Prumerna cena nealko piva za 1l je %.2f.\n", prumer);
}

int main(void){


	/* 1) zeptam se uzivatele, kolik piv */
	printf("Zadejte pocet piv\n");
	int pocet = nactiInt();

	/* 2) vytvorim dost velkou strukturu, aby se vsechno veslo */
	Pivo * basaPiv = (Pivo *) malloc(pocet * sizeof(Pivo));

	/* 3) ukladam polozky, ktere zadava uzivatel */
	nactiData(basaPiv, pocet);
	vypisBasu(basaPiv, pocet, 0);
	/* 4) vypisu vsechna nealko piva */
	printf("----------\n");
	vypisBasu(basaPiv, pocet, 1);

	/* 5) vypisu prumernou cenu za 1l nealko piva */
	prumerCenaNealko(basaPiv, pocet);

	return 0;
}