#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "Plaszczyzna.hh"
using drawNS::Point3D;
using std::vector;

class Powierzchnia: public Plaszczyzna 
{
    public:   
    Powierzchnia();
    Powierzchnia(double max_X, double min_X, double max_Y, double min_Y,double Z, drawNS::Draw3DAPI * api);
    void poziom(double wysokosc) override;
    void rysuj() override;
};
#endif