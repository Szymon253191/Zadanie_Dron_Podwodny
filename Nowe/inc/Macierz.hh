#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
template <class TYP, int ROZMIAR>
class Macierz
{
    Wektor <TYP, ROZMIAR> tab [ROZMIAR];

    public:
    Macierz();
    Wektor <TYP, ROZMIAR> & operator [] (int index);
    const Wektor <TYP, ROZMIAR> & operator [] (int index) const; 
    Wektor <TYP, ROZMIAR> operator * (const Wektor <TYP, ROZMIAR> & W2) const;
    TYP wyznacznik() const;
    Macierz operator + (const Macierz <TYP, ROZMIAR> & M2) const;
    Macierz operator - (const Macierz <TYP, ROZMIAR> & M2) const;
    Macierz operator * (const Macierz <TYP, ROZMIAR> & M2) const;
    Macierz operator * (TYP L2) const;
    bool operator == (const Macierz <TYP, ROZMIAR> & M2) const;
    bool operator != (const Macierz <TYP, ROZMIAR> & M2) const;
    Macierz transponuj() const;
};

template <class TYP, int ROZMIAR>
std::istream & operator >> ( std::istream & strm, Macierz <TYP, ROZMIAR> & M);

template <class TYP, int ROZMIAR>
std::ostream & operator << ( std::ostream & strm, const Macierz <TYP, ROZMIAR> & M);

#endif