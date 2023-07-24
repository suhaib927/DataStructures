/** 
* @file SatirListesi.cpp
* @description CiftYonlu bagli liste (SatirListe).
* @course Egitim Turu: 1 ogretim , Grup: c .
* @assignment Odev No: 1.
* @date 17/11/2022
* @author Isim: SUHAYB ALHAS OTHMAN , E POSTA : suhayb.othman@ogr.sakarya.edu.tr , Ogrenci No: B201210560
*/

#include "SatirListe.hpp"
#include "S_L_Dugum.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


SatirListe::SatirListe(string satir)
{   
    IlkSatirDugum =0;
    int sayi;
    stringstream ss(satir);
    while (ss>>sayi) // satir dan gelen elemanlarin sayisna gore yeni dugumler olusturur.
    {
        SatirDugumEkle(sayi);
    }
}
SatirListe::~SatirListe()
{
    S_L_Dugum* gec = IlkSatirDugum;
    S_L_Dugum* sil;
    while(gec->sonraki != 0)
    {
        sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
    delete gec;
}

void SatirListe::SatirDugumEkle(int veri) 
{
    S_L_Dugum* YeniSatirDugum = new S_L_Dugum(veri);

    if(IlkSatirDugum == 0) {
        IlkSatirDugum = YeniSatirDugum;
    }
    else
    {
        S_L_Dugum* gec;
        gec = IlkSatirDugum;
        while (gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = YeniSatirDugum;
        YeniSatirDugum->onceki = gec;
    }
    SatirDugumSayisi++;
}
S_L_Dugum* SatirListe::SatirDugumGetir(int sira)
{
    int sayac = 0;
    S_L_Dugum* gec = IlkSatirDugum;
    while(gec !=0)
    {
        if(sayac == sira)
            return gec;
        gec = gec->sonraki;
        sayac++;
    }
    return 0;
}
void SatirListe::SL_RastgeleSilme(int sira)
{
    S_L_Dugum* gec = IlkSatirDugum;
    int sayi = rand() % (SatirDugumSayisi); 
    string kesin; 

    bosbirak(sira%8); cout << left <<setw(13) << "^^^^^^^^^^^" << right<<endl;
    for(int i =0;i<SatirDugumSayisi;i++)
    {
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(9) << gec->onceki << "|" << setw(2) << "  "<<endl;
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(5) << gec->veri << setw(5) << "|" << setw(2) << "  ";
        if(i==sayi)
            cout << "   <--- silinecek secili"<<endl;
        else
            cout << endl;
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(9) << gec->sonraki << "|" << setw(2) << "  "<<endl;
        CizgiYaz(sira%8);
        gec = gec->sonraki;
    }
    cin >> kesin;
    if(kesin == "k") // silme isleminin kseinlestirmek 
    {
        S_L_Dugum* sil = SatirDugumGetir(sayi);
        if(sil == 0)
            return;
        S_L_Dugum* onceki = sil->onceki; 
        S_L_Dugum* sonraki = sil->sonraki; 
        if(SatirDugumSayisi != 1)
        {
            if(sonraki)
                sonraki->onceki = onceki;
            if(onceki)
                onceki->sonraki = sonraki;
            else
                IlkSatirDugum = sonraki;
                delete sil;
        }
        SatirDugumSayisi--;
    }
    system("cls");
}
float SatirListe::ortalamaGetir()
{
    float toplam=0;
    S_L_Dugum* gec = IlkSatirDugum;
    while(gec !=0)
    {
        toplam += gec->veri;
        gec =gec->sonraki;
    }
    
    return toplam/SatirDugumSayisi;
}
// SatirListesini Yazdirmak icin
void SatirListe::SLyazdir(int sira)
{
    S_L_Dugum* gec = IlkSatirDugum;
    bosbirak(sira%8); cout << left <<setw(13) << "^^^^^^^^^^^" << right<<endl;
    while(gec !=0)
    {
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(9) << gec->onceki << "|" << setw(2) << "  "<<endl;
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(5) << gec->veri << setw(5) << "|" << setw(2) << "  "<<endl;
        CizgiYaz(sira%8);
        bosbirak(sira%8); cout << "|" << setw(9) << gec->sonraki << "|" << setw(2) << "  "<<endl;
        CizgiYaz(sira%8);
        gec = gec->sonraki;
    }
}
void SatirListe::CizgiYaz(int sira)
{
    cout << setw(13*sira) << "" << "-----------" <<endl;
}
void SatirListe::bosbirak(int sira)
{
    cout << setw(13*sira) << "";
}