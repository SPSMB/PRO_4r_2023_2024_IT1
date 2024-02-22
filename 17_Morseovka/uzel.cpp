#include "uzel.h"

Uzel::Uzel()
{
    znak = '#';
    tecka = NULL;
    carka = NULL;
}

Uzel::Uzel(char znak_c)
{
    znak = znak_c;
    tecka = NULL;
    carka = NULL;
}

Uzel::Uzel(char znak_c, Uzel *tecka_, Uzel *carka_)
{
    znak = znak_c;
    tecka = tecka_;
    carka = carka_;
}
