#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH
#include "MacierzObr.hh"
#include "Dr3D_gnuplot_api.hh"

class Obiekt3D
{
    Wektor <double,3> srodek;
    MacierzObr orientacja;
    int id;
    drawNS::Draw3DAPI *gplt;

    public:
    virtual void rysuj() = 0;
    virtual void wymaz() = 0;
};

#endif