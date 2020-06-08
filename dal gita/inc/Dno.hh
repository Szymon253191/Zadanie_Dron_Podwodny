#ifndef DNO_HH
#define DNO_HH
#include "Plaszczyzna.hh"
using std::vector;
using drawNS::Point3D;

class Dno: public Plaszczyzna
{
    public:
    Dno();
    Dno(double max_X, double min_X, double max_Y, double min_Y,double Z, drawNS::Draw3DAPI *api);
    void rysuj() override;
    void poziom(double wysokosc) override;
};
#endif