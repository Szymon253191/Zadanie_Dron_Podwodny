#ifndef OBIEKT_HH
#define OBIEKT_HH
#include "Wektor.hh"
#include "MacierzObr.hh"
#include <vector>
#include <memory>

using namespace std;
using namespace drawNS;

class Obiekt
{
    shared_ptr<Draw3DAPI> api;
    int id;

    public:
    Obiekt(const shared_ptr<Draw3DAPI> & napi) : api(napi) {id = -1;}
    virtual void rysuj() = 0;
    virtual void zmaz() = 0;
};



#endif