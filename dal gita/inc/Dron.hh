#ifndef DRON_HH
#define DRON_HH
#include "Prostopadloscian.hh"
#include "Interfejs.hh"

class Dron:public Prostopadloscian,public Interfejs
{   
    public:
    Dron(double A, double B, double H, drawNS::Draw3DAPI *api);
    void rysuj() override;
    void wymaz_dron();
    void ruch_drona(double odl) override;
    void obroc_dron(double kat) override;
    void wznies_opusc_dron(double odl) override;
};

#endif