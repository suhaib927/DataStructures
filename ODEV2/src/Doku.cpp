#include "Doku.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Radix.hpp"
using namespace std;
Doku::Doku(string satir)
{
    int sayi;
    Hucre* yeniHucri;
    stringstream ss(satir);
    ss>>sayi;
    ilkHucre = new Hucre(sayi);
    yeniHucri = ilkHucre;
    Hucrelersayisi = 1;
    while(ss>>sayi)
    {
        yeniHucri->sonraki = new Hucre(sayi);
        yeniHucri = yeniHucri->sonraki;
        Hucrelersayisi++;
    }
}
Doku::~Doku()
{
    while(ilkHucre)
    {
        Hucre* sil = ilkHucre;
        ilkHucre = ilkHucre->sonraki;
        delete sil;     
    }
}
int Doku::OrtaHucreGetir()
{
    Radix* radix = new Radix(ilkHucre,Hucrelersayisi);
    int* siraliSayilar = radix->sirala();
    int OurtaHucreninVerisi = siraliSayilar[(Hucrelersayisi)/2];
    delete radix;
    delete[] siraliSayilar;
    return OurtaHucreninVerisi;
} 
