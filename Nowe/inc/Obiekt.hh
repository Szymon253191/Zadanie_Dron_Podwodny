#ifndef OBIEKT_HH
#define OBIEKT_HH
#include " Wektor.hh"
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

class Bryla
{
    Wektor srodek;
    MacierzObr orientacja;

    public:
    Bryla(Wektor nsrodek) : srodek(nsrodek) {}
    void przesun(Wektor nowy) {srodek+=nowy;}
    void obroc(MacierzObr nowa) {orientacja*+nowa;}
};

class Prostopadloscian : public Bryla, public Obiekt 
{
    double wys;
    double szer;
    double gleb;

    public:
    Prostopadloscian(Wektor nsrodek, const shared_ptr<Draw3DAPI> & napi, double nw, double ns, double ng) : Bryla(nsrodek), Obiekt(napi), wys(nw), szer(ns), gleb(ng) {}
    void rysuj() override;
    void zmaz() override;
};

void Prostopadloscian::zmaz()
{
    if (id != -1)
        api.erase_shape(id);
};

void Prostopadloscian::rysuj()
{
    vector<Wektor> v1(4);
    vector<Wektor> v2(4);
    v1[0] = srodek + orientacja * Wektor(-szer/2, -gleb/2, -wys/2);
    v1[1] = srodek + orientacja * Wektor(-szer/2, gleb/2, -wys/2);
    v1[2] = srodek + orientacja * Wektor(szer/2, gleb/2, -wys/2);
    v1[3] = srodek + orientacja * Wektor(szer/2, -gleb/2, -wys/2);

    v2[0] = srodek + orientacja * Wektor(-szer/2, -gleb/2, wys/2);
    v2[1] = srodek + orientacja * Wektor(-szer/2, gleb/2, wys/2);
    v2[2] = srodek + orientacja * Wektor(szer/2, gleb/2, wys/2);
    v2[3] = srodek + orientacja * Wektor(szer/2, -gleb/2, wys/2);

    zmaz();
    api->draw_polyhedron(v1,v2);
};
#endif