#include "Macierz.hh"
template <class TYP, int ROZMIAR>

Macierz<TYP,ROZMIAR>::Macierz()
{
    for(int i=0;i<ROZMIAR;i++)
    {                                                 
        for(int j=0;j<ROZMIAR;j++)
        {                                             
            tab[i][j]=0;                                                            
        }                                                                       
    }             
}

template <class TYP, int ROZMIAR>
const Wektor <TYP,ROZMIAR> & Macierz <TYP,ROZMIAR>::operator [] (int index) const
{
    if(index<0||index>ROZMIAR)
    {
        std::cerr<<"Indeks macierzy znajduje sie poza zakresem";
        exit(1);
    }
    return tab[index];
}

template <class TYP,int ROZMIAR>
Wektor <TYP,ROZMIAR> & Macierz <TYP,ROZMIAR>::operator [] (int index) 
{
    if(index<0||index>ROZMIAR)
    {
        std::cerr<<"Indeks macierzy znajduje sie poza zakresem";
        exit(1);
    }
    return tab[index];
}

template <class TYP, int ROZMIAR>
Wektor <TYP, ROZMIAR>  Macierz <TYP, ROZMIAR>::operator * (const Wektor <TYP, ROZMIAR> & W2) const
{
   Wektor <TYP, ROZMIAR> wynik;
   for(int i=0;i<ROZMIAR;i++)
   {
       wynik[i] = this->tab[i] * W2;
   } 
   return wynik;
}


template <class TYP,int ROZMIAR>
TYP Macierz<TYP,ROZMIAR>::wyznacznik() const
{
    Macierz <TYP,ROZMIAR> wynik = *this;
    int pom = 0;
    int k = 0;
    double epsilon=0.000000001;
    TYP det = 0;
    for(int j=0;j<ROZMIAR;j++)
    {
        if(wynik[j].dlugosc() < epsilon || (wynik.Transponuj()[j].dlugosc() < epsilon))
        {
            det = 0;
            return det;
        } 
        while (std::abs(wynik[j][j])<epsilon)
        {
            std::swap(wynik[j],wynik[++pom]);
            ++k;
        }
        pom=0;
        for(int i=(j+1);i<ROZMIAR;i++)
        {
            wynik[i] = wynik[i]-(wynik[j]*(wynik[i][j]/wynik[j][j])); 
        }
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        int j;
        j = i;
        det *= wynik[i][j];
    }
    if(k%2==0)
    return det;
    else
    return det*(-1);
}

template <class TYP,int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator + (const Macierz <TYP,ROZMIAR> & M2) const
{
    Macierz <TYP,ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        wynik[i] = this->tab[i] + M2[i];
    }
    return wynik;
}

template <class TYP,int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz<TYP,ROZMIAR>::operator - (const Macierz<TYP,ROZMIAR> & M2) const
{
    Macierz <TYP,ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        wynik[i] = this->tab[i] - M2[i];
    }
    return wynik;
}

template <class TYP,int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator * (const Macierz <TYP,ROZMIAR> & M2) const 
{
    Macierz <TYP, ROZMIAR> wynik;
    Macierz <TYP, ROZMIAR> Mtemp = M2.transponuj();
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            wynik[i][j] = this->tab[i] * (Mtemp[j]);
        }
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::operator * (TYP L2) const
{
    Wektor <TYP,ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        wynik[i] = tab[i] * L2;
    }
    return wynik;
}

template <class TYP, int ROZMIAR>
bool Macierz <TYP, ROZMIAR>::operator == (const Macierz <TYP,ROZMIAR> & M2) const
{
    for(int i=0;i<ROZMIAR;i++)
    {
        if(!(this->tab[i] == M2[i]))
        return false;
    }
    return true;
}

template <class TYP,int ROZMIAR>
bool Macierz <TYP,ROZMIAR>::operator != (const Macierz <TYP,ROZMIAR> & M2) const
{
    return !(*this == M2);
}

template <class TYP,int ROZMIAR>
Macierz <TYP,ROZMIAR> Macierz <TYP,ROZMIAR>::transponuj() const
{
    Macierz<TYP,ROZMIAR> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            wynik[i][j] = this->tab[j][i];
        }
    }
    return wynik; 
}

template <class TYP,int ROZMIAR>
std::istream & operator >> (std::istream & strm,Macierz <TYP,ROZMIAR> & Mac)
{
    for (int i=0;i<ROZMIAR;++i)
    {
        strm >> Mac[i];
    }
    return strm;
}

template <class TYP,int ROZMIAR>
std::ostream & operator << (std::ostream & strm,const Macierz <TYP,ROZMIAR> & Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        strm << Mac[i] << std::endl; 
    }
}
