#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Obiekt3D.hh"
using drawNS::Point3D;
using std::vector;

class Prostopadloscian:public Obiekt3D
{
    protected:
    double dl_bokow[3]
    Wektor <double,3> wierzcholki[8];
    ustal_wierzcholki();

    public:
    Prostopadloscian();
    Prostopadloscian(double A, double B, double H, drawNS::Draw3DAPI *api);
    void wymaz() override;
    void rysuj() override;
    void jazda(double odl);
    void obrot(double kat);
    void gora_dol(double odl);
};

#endif