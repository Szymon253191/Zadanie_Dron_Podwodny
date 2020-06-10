#include "Prostopadloscian.hh"
Prostopadloscian::Prostopadloscian()
{
    dl_bokow = Wektor<double,3> W;
}

Prostopadloscian::Prostopadloscian(double A,double B, double H,drawNS::Draw3DAPI *api)
{
    dl_bokow[0] = A;
    dl_bokow[1] = B;
    dl_bokow[2] = H;
    (*this).gplt = api;
}

void Prostopadloscian::ustal_wierzcholki()
{
    Wektor <double,3> Ana2((*this).dl_bokow[0]/2,0,0);
    Wektor <double,3> Bna2(0,(*this).dl_bokow[1]/2,0);
    Wektor <double,3> Hna2(0,0,(*this).dl_bokow[2]/2);
    (*this).wierzcholki[0] = (*this).srodek + (*this).orientacja * ((Ana2+Bna2+Hna2)*(-1));
    (*this).wierzcholki[1] = (*this).srodek + (*this).orientacja * (Ana2-Bna2-Hna2);
    (*this).wierzcholki[2] = (*this).srodek + (*this).orientacja * (Ana2+Bna2-Hna2);
    (*this).wierzcholki[3] = (*this).srodek + (*this).orientacja * (Bna2-Ana2-Hna2);
    (*this).wierzcholki[4] = (*this).srodek + (*this).orientacja * (Hna2-Bna2-Ana2);
    (*this).wierzcholki[5] = (*this).srodek + (*this).orientacja * (Ana2-Bna2+Hna2);
    (*this).wierzcholki[6] = (*this).srodek + (*this).orientacja * (Ana2+Bna2+Hna2);
    (*this).wierzcholki[7] = (*this).srodek + (*this).orientacja * (Bna2-Ana2+Hna2);
}
 
void Prostopadloscian::rysuj()
{
    (*this).ustal_wierzcholki();
    (*this).id = gplt.draw_polyhedron(vector<vector<Point3D>>
    {
        {
            {
                drawNS::Point3D((*this).wierzcholki[0][0],(*this).wierzcholki[0][1],(*this).wierzcholki[0][2]),
                drawNS::Point3D((*this).wierzcholki[1][0],(*this).wierzcholki[1][1],(*this).wierzcholki[1][2]),
                drawNS::Point3D((*this).wierzcholki[2][0],(*this).wierzcholki[2][1],(*this).wierzcholki[2][2])
            },
            {
                drawNS::Point3D((*this).wierzcholki[3][0],(*this).wierzcholki[3][1],(*this).wierzcholki[3][2]),
                drawNS::Point3D((*this).wierzcholki[4][0],(*this).wierzcholki[4][1],(*this).wierzcholki[4][2]),
                drawNS::Point3D((*this).wierzcholki[5][0],(*this).wierzcholki[5][1],(*this).wierzcholki[5][2])
            },
            {
                drawNS::Point3D((*this).wierzcholki[6][0],(*this).wierzcholki[6][1],(*this).wierzcholki[6][2]),
                drawNS::Point3D((*this).wierzcholki[7][0],(*this).wierzcholki[7][1],(*this).wierzcholki[7][2]),
                drawNS::Point3D((*this).wierzcholki[8][0],(*this).wierzcholki[8][1],(*this).wierzcholki[8][2])
            }
        }
    },"black")
}

void Prostopadloscian::wymaz()
{
    (*this).gplt->erase_shape((*this).id);
}

void Prostopadloscian::jazda(double odl)
{
    Wektor <double,3> jazda(0,odl,0);
    (*this).gplt.erase_shape((*this).id);
    (*this).srodek = (*this).srodek + (*this).orientacja * jazda;
    (*this).rysuj();
}

void Prostopadloscian::obrot(double kat)
{
    MacierzObr nowa_orientacja('Z',kat); 
    (*this).gplt.erase_shape((*this).id);
    (*this).orientacja = (*this).orientacja * nowa_orientacja;
    (*this).rysuj();
}

void Prostopadloscian::gora_dol(double odl)
{
    (*this).gplt.erase_shape((*this).id);
    (*this).srodek[2] += odl;
    (*this).rysuj();
}