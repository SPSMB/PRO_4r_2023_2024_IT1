#include "morseovka.h"

Morseovka::Morseovka()
{
    koren = vytvorStrom();
}

Uzel * Morseovka::vytvorStrom()
{
    return novyUzel(' ',
            novyUzel('E',                   /* .    */
             novyUzel('I',                  /* ..   */
              novyUzel('S',                 /* ...  */
               novyUzel('H',NULL,NULL),     /* .... */
               novyUzel('V',NULL,NULL)),    /* ...- */
              novyUzel('U',                 /* ..-  */
               novyUzel('F',NULL,NULL),     /* ..-. */
               NULL)),
             novyUzel('A',                  /* .-   */
              novyUzel('R',                 /* .-.  */
               novyUzel('L',NULL,NULL),     /* .-.. */
               NULL),
              novyUzel('W',                 /* .--  */
               novyUzel('P',NULL,NULL),     /* .--. */
               novyUzel('J',NULL,NULL)))),  /* .--- */
            novyUzel('T',                   /* -    */
             novyUzel('N',                  /* -.   */
              novyUzel('D',                 /* -..  */
               novyUzel('B',NULL,NULL),     /* -... */
               novyUzel('X',NULL,NULL)),    /* -..- */
              novyUzel('K',                 /* -.-  */
               novyUzel('C',NULL,NULL),     /* -.-. */
               novyUzel('Y',NULL,NULL))),   /* -.-- */
             novyUzel('M',                  /* --   */
              novyUzel('G',                 /* --.  */
               novyUzel('Z',NULL,NULL),     /* --.. */
               novyUzel('Q',NULL,NULL)),    /* --.- */
                      novyUzel('O',NULL,NULL))));   /* ---  */
}

Uzel * Morseovka::novyUzel(char z, Uzel *t, Uzel *c)
{
    Uzel * aktualni = new Uzel(z, t, c);
    return aktualni;
}

void Morseovka::dekoduj(string &vstup, string &vystup)
{
    char z;
    unsigned int i = 0;
    Uzel * aktualni = koren;
    while(i < vstup.length()){
        z = vstup[i];

        if(aktualni != NULL){
            if(z == '*') {
                aktualni = aktualni->tecka;
            } else if(z == '-'){
                aktualni = aktualni->carka;
            } else {
                vystup.append(1, aktualni->znak);
                aktualni = koren;
            }
            i++;
        } else {
            while(vstup[i] == '*' || vstup[i] == '-'){
                i++;
            }
            vystup.append(1,'?');
            i++;
            aktualni = koren;
        }
    }
    vystup.append(1, aktualni->znak);
}
