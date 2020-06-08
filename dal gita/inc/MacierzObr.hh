#ifndef MACIERZOBR_HH
#define MACIERZOBR_HH
#include "Macierz.hh"
include <cmath>

enum Os
{
    X,Y,Z
};

class MacierzObr:public Macierz <double,3>
{
    public:
    MacierzObr();
    MacierzObr(const Macierz <double,3> & M);
    MacierzObr(Os TYP, double kat);
};

#endif