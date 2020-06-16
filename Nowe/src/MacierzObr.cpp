#include "MacierzObr.hh"
MacierzObr::MacierzObr()
{
    for(int i=0;i<3;i++)
    {
        tab[i][i] = 1;
    }
}
MacierzObr::MacierzObr(const Macierz<double,3> & Mac)
{
    double epsilon=0.000000001;
    if(abs(tab[0]*tab[1])>epsilon || abs(tab[1]*tab[2])>epsilon || abs(tab[0]*tab[2])>epsilon || abs((*this).wyznacznik()-1>epsilon))
    {
        std::cerr<<"Macierz ta nie jest ortogonalna\n";
        exit(1);
    }
}

MacierzObr::MacierzObr(Os TYP, double kat)
{
    kat = kat * 3.1416 / 180;
    switch(TYP)
    {
        case X:
        {
            tab[0][0] = 1;
            tab[0][1] = 0;
            tab[0][2] = 0;
            tab[1][0] = 0;
            tab[1][1] = cos(kat);
            tab[1][2] = -sin(kat);
            tab[2][0] = 0;
            tab[2][1] = sin(kat);
            tab[2][2] = cos(kat);
            break;
        }
        case Y:
        {
            tab[0][0] = cos(kat);
            tab[0][1] = 0;
            tab[0][2] = sin(kat);
            tab[1][0] = 0;
            tab[1][1] = 1;
            tab[1][2] = 0;
            tab[2][0] = -sin(kat);
            tab[2][1] = 0;
            tab[2][2] = cos(kat);
            break;
        }
        case Z:
        {
            tab[0][0] = cos(kat);
            tab[0][1] = -sin(kat);
            tab[0][2] = 0;
            tab[1][0] = sin(kat);
            tab[1][1] = cos(kat);
            tab[1][2] = 0;
            tab[2][0] = 0;
            tab[2][1] = 0;
            tab[2][2] = 1;
            break;
        }
    }
}