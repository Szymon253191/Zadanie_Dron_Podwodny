#include "Dno.hh"

Dno::Dno()
{
  dl_bokow = Wektor<double,3> W;
}

Dno::Dno(double max_X, double min_X, double max_Y, double min_Y,double Z, drawNS::Draw3DAPI * api)
{
  granice[0] = max_X;
  granice[1] = min_X;
  granice[2] = max_Y;
  granice[3] = min_Y;
  granice[4] = Z;
  (*this).gplt = api;
}

void Dno::poziom(double wysokosc)
{
  (*this).granice[4]=wysokosc;
}

void Dno::rysuj()
{
  (*this).id=(*this).gplt->draw_surface(vector<vector<Point3D>> 
  {
  {
	    drawNS::Point3D(0,(*this).granice[2],(*this).granice[4]), 
      drawNS::Point3D(0,0,(*this).granice[4]), 
      drawNS::Point3D(0,(*this).granice[3],(*this).granice[4])       
	},
  {
	    drawNS::Point3D((*this).granice[0],(*this).granice[2],(*this).granice[4]),
      drawNS::Point3D((*this).granice[0],0,(*this).granice[4]), 
      drawNS::Point3D((*this).granice[0],(*this).granice[3],(*this).granice[4])
	},
  {
	    drawNS::Point3D((*this).granice[1],(*this).granice[2],(*this).granice[4]), 
      drawNS::Point3D((*this).granice[1],0,(*this).granice[4]), 
      drawNS::Point3D((*this).granice[1],(*this).granice[3],(*this).granice[4])       
	}
  },"yellow");
}