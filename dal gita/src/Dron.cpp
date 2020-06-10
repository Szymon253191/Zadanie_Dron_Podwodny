#include "Dron.hh"

Dron(double A, double B, double H, drawNS::Draw3DAPI *api)
{
    dl_bokow[0] = A;
    dl_bokow[1] = B;
    dl_bokow[3] = H;
    gnpl = api;
}

void rysuj() override
{
    (*this).rysuj();
}

void wymaz_dron()
{
    (*this).wymaz();
}

void ruch_drona(double odl) override
{
    (*this).jazda(); //bez animacji chyba
}

void obroc_dron(double kat) override
{
    (*this).obrot(); //bez animacji chyba
}

void gora_dol(double odl) override
{
    (*this).gora_dol(); //bez animacji chyba
}