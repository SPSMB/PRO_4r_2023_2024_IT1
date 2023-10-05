#include <stdio.h>
#define DELKAPOLE 50

/* generuje odjezdy hloupe podle predpisu
	pole - ukazatel na pole, kam se odjezdy generuji
	delka - delka pole
	interval - jak casto muze vlak jet
	start - nejdrivejsi odjezd
	konec - nejpozdejsi odjezd
*/

void generujOdjezdy(int * pole, int delka, int interval, int start, int konec){
	pole[0] = start;
	for (int i = 1; i < delka; ++i)
	{
		int foo = pole[i-1] + interval;
		if (foo > konec)
			break;
		pole[i] = foo;
	}
}

/* generuje inteligentni odjezdy - tedy navazuje na predchozi vlak
	VLAK NAVAZUJE, KDYZ ODJIZDI O 0-10 MINUT POZDEJI
   nove_pole - tam se generuji nove odjezdy
   ref_pole - odjezdy vlaku, na ktery novy musi navazovat
   delka - delka pole
   interval - interval noveho vlaku (jak nejcasteji muze novy vlak jezdit) 
*/
void inteligentniOdjezdy(int * nove_pole, int * ref_pole, int delka, int interval){

	nove_pole[0] = ref_pole[0];
	int r = 1; /* index do referencniho pole */
	int i = 1; /* index do noveho pole */

	/* prochazim referencni pole */
	for( ;ref_pole[r] != -1; r++){
		int hornimez = ref_pole[r];
		/* do noveho pole zkusim dostat maximum vlaku, tak aby navazovaly*/
		int hodnota = nove_pole[i-1];
		while(1){
			hodnota = hodnota + interval;
			/* 1. navazujici vlak jede pozdeji a do limitu na prestup se vejde */
			if(hodnota > hornimez && (hodnota-hornimez) <= 10){
				nove_pole[i] = hodnota;
				i++;
				break;
			/* 2. navazujici vlak jede drive a dalsi se stihne do prestupu */
			} else if(hodnota < hornimez && (hodnota+interval) <= (hornimez+10)){
				nove_pole[i] = hodnota;
				i++;
			/* 3. navazujici vlak jede drive a dalsi by se nestihl navazat na prestup) */
			} else {
				hodnota = hornimez;
				nove_pole[i] = hodnota;
				i++;
				break;
			}
		}
	}

}

/* chytrejsi vypis pole - rovnou prevadi minutove hodnoty na format hh:mm */
void vypisPole(int * pole, int delka){
	for(int i = 0; i < delka; i++)
	{
		if(pole[i] != -1){
			int hod = pole[i] / 60;
			int min = pole[i] % 60;
			printf("%d:%02d", hod, min);
			printf(" ");
		}
	}
	printf("\n");
}

/* nastavi do pole pocatecni hodnotu -1 */
void resetPole(int * pole, int delka){
	for(int i = 0; i < delka; i++){
		pole[i] = -1;
	}
}

int main(void){

	int v1_interval = 90;
	int v2_interval = 170;
	int v3_interval = 40;

	// odjezdy vlaku ukladam do pole
	int v1[DELKAPOLE]; resetPole(v1, DELKAPOLE);
	int v2[DELKAPOLE]; resetPole(v2, DELKAPOLE);
	int v3[DELKAPOLE]; resetPole(v3, DELKAPOLE);

	/* generuji odjezdy pro vlak s nejdelsim okruhem */
	// void generujOdjezdy(int * pole, int delka, int interval, int start, int konec)
	generujOdjezdy(v2, DELKAPOLE, v2_interval, 300, 1380);
	printf("Odjezdy vlaku na Karlstejn:\n"); vypisPole(v2, DELKAPOLE);

	/* generuji odjezdy pro vlak s 2. nejdelsim okruhem */
	inteligentniOdjezdy(v1, v2, DELKAPOLE, v1_interval);
	printf("Odjezdy vlaku do Nizboru:\n"); vypisPole(v1, DELKAPOLE);

	/* generuji odjezdy pro vlak s 3. nejdelsim okruhem */
	inteligentniOdjezdy(v3, v1, DELKAPOLE, v3_interval);
	printf("Odjezdy vlaku do cementarny:\n"); vypisPole(v3, DELKAPOLE);

	return 0;
}