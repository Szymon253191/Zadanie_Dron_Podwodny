#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Obiekt.hh"
#include "Prostopadloscian.hh"

using namespace std;
using namespace drawNS;

void wait4key()
{
    do
    {
       cout <<"\n Press a key to continue...\n";
    } while (cin.get() != '\n');
}

int main()
{
    Wektor <double, 3> A (0,0,0);
    int przestrzenX, przestrzenY, przestrzenZ;
    cout <<"Podaj wymiary przestrzeni X, Y, Z:\n";
    cin >> przestrzenX >> przestrzenY >> przestrzenZ;
    Draw3DAPI * api = new APIGnuPlot3D(-przestrzenX,przestrzenX,-przestrzenY,przestrzenY,-przestrzenZ,przestrzenZ, 1000);
    Prostopadloscian P(A,api,3,4,5);
    P.rysuj();
    P.przesun(Wektor<double, 3>(2,2,3));
    P.rysuj();
}
