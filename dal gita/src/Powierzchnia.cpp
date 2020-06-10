#include "Powierzchnia.hh"

Powierzchnia::Powierzchnia()
{
    dl_bokow = Wektor<double,3> W;
}

Powierzchnia::Powierzchnia(double max_X, double min_X, double max_Y, double min_Y,double Z, drawNS::Draw3DAPI * api)
{
  wymiar[0] = max_X;
  wymiar[1] = min_X;
  wymiar[2] = max_Y;
  wymiar[3] = min_Y;
  wymiar[4] = Z;
  (*this).gplt = api;
}

void Powierzchnia::poziom(double wysokosc)
{
  (*this).wymiar[4]=wysokosc;
}
void Powierzchnia::Rysuj()
{
  (*this).id=(*this).gplt->draw_surface(vector<vector<Point3D> > 
  {
    {
        {
          drawNS::Point3D(0,(*this).wymiar[2],(*this).wymiar[4]), 
          drawNS::Point3D(0,(*this).wymiar[3],(*this).wymiar[4]), 
          drawNS::Point3D(0,0,(*this).wymiar[4])
        },
        {
          drawNS::Point3D((*this).wymiar[0],(*this).wymiar[2],(*this).wymiar[4]), 
          drawNS::Point3D((*this).wymiar[0],0,(*this).wymiar[4]), 
          drawNS::Point3D((*this).wymiar[0],(*this).wymiar[3],(*this).wymiar[4]),
        },
        {
          drawNS::Point3D((*this).wymiar[1],(*this).wymiar[2],(*this).wymiar[4]), 
          drawNS::Point3D((*this).wymiar[1],0,(*this).wymiar[4]), 
          drawNS::Point3D((*this).wymiar[1],(*this).wymiar[3],(*this).wymiar[4])  
        }
    }
  },"blue");
}