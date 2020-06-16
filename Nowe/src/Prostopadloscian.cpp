#include "Prostopadloscian.hh"

void Prostopadloscian::zmaz()
{
    if (id != -1)
        (*api).erase_shape(id);
};

void Prostopadloscian::rysuj()
{
    vector <Wektor<double, 3>> v1(4);
    vector <Wektor<double, 3>> v2(4);
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