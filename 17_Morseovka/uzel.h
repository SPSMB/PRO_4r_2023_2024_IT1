#ifndef UZEL_H
#define UZEL_H
#include <stddef.h>


class Uzel
{
public:
    char znak;
    Uzel * tecka;
    Uzel * carka;
    Uzel();
    Uzel(char znak_c);
    Uzel(char znak_c, Uzel * tecka_, Uzel * carka_);
};

#endif // UZEL_H
