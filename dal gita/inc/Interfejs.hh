#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include "Wektor.hh"

class Interfejs
{
    public:
    virtual void jazda(double odl) = 0;
    virtual void obroc_dron(double kat) = 0;
    virtual void wznies_opusc_dron(double odl) = 0;
};
#endif