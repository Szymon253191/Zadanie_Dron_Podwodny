#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
#include "Obiekt3D.hh"

class Plaszczyzna:public Obiekt3D
{
    protected:
    double wymiar[5];
    
    public:
    virtual void poziom(double wysokosc)=0;
};
#endif