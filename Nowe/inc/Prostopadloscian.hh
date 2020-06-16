#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "MacierzObr.hh"
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Bryla.hh"
#include "Obiekt.hh"
#include <vector>
#include <memory>

class Prostopadloscian : public Bryla , public Obiekt 
{
    double wys;
    double szer;
    double gleb;

    public:
    Prostopadloscian(Wektor<double, 3> nsrodek, const shared_ptr<Draw3DAPI> & napi, double nw, double ns, double ng) : Bryla(nsrodek), Obiekt(napi), wys(nw), szer(ns), gleb(ng) {};
    void rysuj() override;
    void zmaz() override;
};

#endif