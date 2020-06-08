#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH
#include "Obiekt3D.hh"
using drawNS::Point3D;
using std::vector;
class Graniastoslup6:public Obiekt3D 
{
    protected:
    MacierzObr Wirnik;
    double dl_bokow[2];
    Wektor <double,3> wierzcholki[12];
    void ustaw_wierzcholki();
    
    public:
    Graniastoslup6();
    Graniastoslup6(double A,double H, drawNS::Draw3DAPI *api);
    void rysuj() override;
    void wirowanie(double kat);
    void jazda(double odl);
    void obrot(double kat);
    void gora_dol(double odl);
};
#endif