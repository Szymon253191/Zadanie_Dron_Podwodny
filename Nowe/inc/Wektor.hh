#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <iostream>

template <class TYP, int ROZMIAR>
class Wektor
{
    TYP tab[ROZMIAR];
    public:
    Wektor();
    Wektor(TYP X, TYP Y, TYP Z):tab{X,Y,Z}{}
    TYP & operator [] (int index);
    const TYP & operator [] (int index) const;
    Wektor operator + (const Wektor <TYP,ROZMIAR> & W2) const;
    Wektor operator - (const Wektor <TYP,ROZMIAR> & W2) const;
    Wektor operator * (const Wektor <TYP,ROZMIAR> & W2) const;
    Wektor operator * (TYP L2) const;
    Wektor operator / (TYP L2) const;
    Wektor operator += (const Wektor <TYP, ROZMIAR> & W2) const;
    double dlugosc() const
    {
        return sqrt(*this * *this);
    }
    bool operator == (const Wektor <TYP,ROZMIAR> & W2) const;
    bool operator != (const Wektor <TYP,ROZMIAR> & W2) const;
};
template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream & strm, Wektor <TYP,ROZMIAR> & W);
template <class TYP, int ROZMIAR>          
std::ostream & operator << (std::ostream & strm,const Wektor <TYP,ROZMIAR> & W);
#endif
