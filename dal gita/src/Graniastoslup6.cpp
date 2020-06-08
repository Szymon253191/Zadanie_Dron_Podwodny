#include "Graniastoslup6.hh"

Graniastoslup6::Graniastoslup6()
{
    dl_bokow = Wektor<double,3> W;
}

Graniastoslup6::Graniastoslup6(double A,double H,drawNS::Draw3DAPI *api)
{
    dl_bokow[0]=A;
    dl_bokow[1]=H;
    (*this).gplt=api;

}
void Graniastoslup6::ustaw_wierzcholki()
{
    Wektor <double,3> Ana2((*this).dl_bokow[0]/2,0,0);
    Wektor <double,3> Hna2(0,(*this).dl_bokow[1]/2,0);
    Wektor <double,3> WysNaA(0,0,((*this).dl_bokow[0]*sqrt(3))/2);
    (*this).wierzcholki[0]=(*this).srodek+(*this).orientacja*(*this).Wirnik*((Ana2+Hna2+WysNaA)*(-1));
    (*this).wierzcholki[1]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2-Hna2-WysNaA);
    (*this).wierzcholki[2]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2*2-Hna2);
    (*this).wierzcholki[3]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2-Hna2+WysNaA);
    (*this).wierzcholki[4]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(WysNaA-Ana2-Hna2);
    (*this).wierzcholki[5]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2*(-2)-Hna2);
    (*this).wierzcholki[6]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Hna2-Ana2-WysNaA);
    (*this).wierzcholki[7]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2+Hna2-WysNaA);
    (*this).wierzcholki[8]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2*2+Hna2);
    (*this).wierzcholki[9]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2+Hna2+WysNaA);
    (*this).wierzcholki[10]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(WysNaA+Hna2-Ana2);
    (*this).wierzcholki[11]=(*this).srodek+(*this).orientacja*(*this).Wirnik*(Ana2*(-2)+Hna2);
}
void Graniastoslup6::Rysuj()
{
    (*this).ustaw_wierzcholki();
    (*this).id=(*this).gplt->draw_polyhedron(vector<vector<Point3D> > 
    {
        {                                         
            drawNS::Point3D((*this).wierzcholki[0][0],(*this).wierzcholki[0][1],(*this).wierzcholki[0][2]), 
            drawNS::Point3D((*this).wierzcholki[1][0],(*this).wierzcholki[1][1],(*this).wierzcholki[1][2]), 
            drawNS::Point3D((*this).wierzcholki[2][0],(*this).wierzcholki[2][1],(*this).wierzcholki[2][2]),
            drawNS::Point3D((*this).wierzcholki[3][0],(*this).wierzcholki[3][1],(*this).wierzcholki[3][2]),
            drawNS::Point3D((*this).wierzcholki[4][0],(*this).wierzcholki[4][1],(*this).wierzcholki[4][2]), 
            drawNS::Point3D((*this).wierzcholki[5][0],(*this).wierzcholki[5][1],(*this).wierzcholki[5][2])             
        },
        {                                                                                  
            drawNS::Point3D((*this).wierzcholki[6][0],(*this).wierzcholki[6][1],(*this).wierzcholki[6][2]),
            drawNS::Point3D((*this).wierzcholki[7][0],(*this).wierzcholki[7][1],(*this).wierzcholki[7][2]), 
            drawNS::Point3D((*this).wierzcholki[8][0],(*this).wierzcholki[8][1],(*this).wierzcholki[8][2]),
            drawNS::Point3D((*this).wierzcholki[9][0],(*this).wierzcholki[9][1],(*this).wierzcholki[9][2]),
            drawNS::Point3D((*this).wierzcholki[10][0],(*this).wierzcholki[10][1],(*this).wierzcholki[10][2]), 
            drawNS::Point3D((*this).wierzcholki[11][0],(*this).wierzcholki[11][1],(*this).wierzcholki[11][2])            
        }
    },"black");
}

void Graniastoslup6::wirowanie(double kat)
{
    MacierzObr Nowy_wirnik('Y',kat);
    (*this).gplt.erase_shape((*this).id);
    (*this).Wirnik = (*this).Wirnik * Nowy_wirnik;
    (*this).rysuj();
}

void Graniastoslup6::jazda(double odl)
{
    Wektor <double,3> jazda(0,odl,0);
    (*this).gplt.erase_shape((*this).id);
    (*this).srodek = (*this).srodek + (*this).orientacja * jazda;
    (*this).rysuj();
}

void Graniastoslup6::obrot(double kat)
{
    MacierzObr nowa_orientacja('Z',kat);
    (*this).gplt.erase_shape((*this).id);
    (*this).orientacja = (*this).orientacja * nowa_orientacja;
    (*this).rysuj();
}

void Graniastoslup6::gora_dol(double odl)
{
    (*this).gplt.erase_shape((*this).id);
    (*this).srodek[2] += odl;
    (*this).rysuj();
}