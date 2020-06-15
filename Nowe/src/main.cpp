#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Obiekt.hh"

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
    int przestrzenX, przestrzenY, przestrzenZ;
    cout <<"Podaj wymiary przestrzeni X, Y, Z:\n";
    cin >> przestrzenX >> przestrzenY >> przestrzenZ;
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuplot3D(-przestrzenX,przestrzenX,-przestrzenY,przestrzenY,-przestrzenZ,przestrzenZ, 1000));
    Prostopadloscian P(Wektor(0,0,0),api,3,4,5);
    P.rysuj();
    P.przesun(Wektor(2,2,3));
    P.rysuj();
}
