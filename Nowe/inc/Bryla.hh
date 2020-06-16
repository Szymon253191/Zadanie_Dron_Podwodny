#ifndef BRYLA_HH
#define BRYLA_HH
#include "Wektor.hh"
#include "MacierzObr.hh"
#include <vector>
#include <memory>

class Bryla
{
    Wektor<double, 3> srodek;  
    MacierzObr orientacja;

    public:
    Bryla(Wektor<double, 3> nsrodek) : srodek(nsrodek) {}
    void przesun(Wektor<double, 3> nowy) {srodek = srodek + nowy;}
    void obroc(MacierzObr nowa) {orientacja = orientacja * nowa;}
};

#endif