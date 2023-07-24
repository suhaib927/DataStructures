/** 
* @file YoneticiListesi.cpp
* @description CiftYonlu bagli liste olusturdum , ve listenin icinde her dugumun  icinde SatirListesi(cift yonlu bagli liste) bulunur.
* @course Egitim Turu: 1 ogretim , Grup: c .
* @assignment Odev No: 1.
* @date 17/11/2022
* @author Isim: SUHAYB ALHAS OTHMAN , E POSTA : suhayb.othman@ogr.sakarya.edu.tr , Ogrenci No: B201210560
*/
#include "YoneticiListesi.hpp"
#include "SatirListe.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

YoneticiListesi::YoneticiListesi() 
{
    IlkYoneticiDugum =0;
    ifstream file ("veriler.txt");
    string satir;
    while(getline(file,satir)) // dosyadan satir satir okur ve o Stiri YoneticiEkle fonksiyonuna gonderir
    {
        YoneticiEkle(satir);
    }
    siralama();
}
YoneticiListesi::~YoneticiListesi()
{
    Y_L_Dugum* gec = IlkYoneticiDugum;
    Y_L_Dugum* sil;
    if(gec != 0)
    {
    while(gec->sonraki != 0)
    {
        sil = gec;
        gec = gec->sonraki;
        delete sil;
    }
    delete gec->S_Liste;
    }
    delete gec;
    cout <<"dugum silme islemi tamamlandi" <<endl;
}


void YoneticiListesi::basla()
{

    string sec;
    int YLsira = 0;
    int SLsira = 0;
    do
    {
        system("cls");
        if ( sec =="a")
        {
            if(YLsira !=0)
            {
                YLsira -= 8;
                SLsira = YLsira;
            }
        }
        else if (sec == "d")
        {
            if(Yldugumsayisi-YLsira > 8)
            {
                YLsira += 8;
                SLsira = YLsira;
            }
        }
        else if(sec == "c")
        {
            if(SLsira !=  Yldugumsayisi-1)
            {
                if(SLsira >= YLsira+7)
                {
                    SLsira++;
                    YLsira += 8;
                    system("cls");
                }
                else
                    SLsira++;
            }
        }
        else if(sec == "z")
        {
            if(SLsira != 0)
            {    
                if(SLsira == YLsira)
                {
                    SLsira--;
                    YLsira -= 8;
                    system("cls");
                }
                else
                    SLsira--;
            }
        }
        else if(sec == "p")
        {
            YLsil(SLsira);
            if(SLsira == Yldugumsayisi)
                SLsira--;
            if(YLsira == Yldugumsayisi)
                YLsira -= 8;
            if(Yldugumsayisi == 0)
            {
                delete this;
                break;
            }
        }
        else if(sec == "k")
        {
            YLyazdir(YLsira);
            SLsil(SLsira);
            if(SLsira == Yldugumsayisi)
                SLsira--;
            if(YLsira == Yldugumsayisi)
                YLsira -= 8;
        }
        YLyazdir(YLsira);
        SLyazdir(SLsira);
    }while(cin >> sec);
}
void YoneticiListesi::YoneticiEkle(string satir)
{
    Y_L_Dugum* yeniYoneticiDugum = new Y_L_Dugum();
    yeniYoneticiDugum->S_Liste =new SatirListe(satir);
    yeniYoneticiDugum->ortalama = yeniYoneticiDugum->S_Liste->ortalamaGetir();
    if(IlkYoneticiDugum == 0) {
        IlkYoneticiDugum = yeniYoneticiDugum;
    }
    else
    {
        Y_L_Dugum* gec;
        gec = IlkYoneticiDugum;
        while(gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeniYoneticiDugum;
        yeniYoneticiDugum->onceki = gec;
    }
    Yldugumsayisi++;
    
}
void YoneticiListesi::YLsil(int sira)
{
    Y_L_Dugum* sil = YoneticiDugumGetir(sira);
    if(sil == 0)
        return;
    Y_L_Dugum* onceki = sil->onceki; 
    Y_L_Dugum* sonraki = sil->sonraki; 

    if(sonraki)
        sonraki->onceki = onceki;
    if(onceki)
        onceki->sonraki = sonraki;
    else
        IlkYoneticiDugum = sonraki;
    delete sil;
    Yldugumsayisi--;
    if(Yldugumsayisi == 0)
        IlkYoneticiDugum = 0;
    siralama();
}
void YoneticiListesi::SLsil(int sira)
{
    Y_L_Dugum* Yonetici = YoneticiDugumGetir(sira);
    Yonetici->S_Liste->SL_RastgeleSilme(sira);
    if(Yonetici->S_Liste->SatirDugumSayisi == 0)
    {
        this->YLsil(sira);
    }
    else
        Yonetici->ortalama = Yonetici->S_Liste->ortalamaGetir();
    siralama();
}

Y_L_Dugum* YoneticiListesi::YoneticiDugumGetir(int sira)
{
    int sayac = 0;
    Y_L_Dugum* gec = IlkYoneticiDugum;
    while(gec !=0)
    {
        if(sayac == sira)
            return gec;
        gec = gec->sonraki;
        sayac++;
    }
    return 0;
}

//yaz
void YoneticiListesi::YLyazdir(int basla)
{
    ustyaz(basla);
    Adresiyaz(basla);
    altyaz(basla);
    oncekiyaz(basla);
    altyaz(basla);
    ortalamayaz(basla);
    altyaz(basla);
    sonrakiyaz(basla);
    altyaz(basla);
}   
void YoneticiListesi::altyaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    for(int i=0 ; i< 8 ;i++)
    {
        cout << setw(11) << "-----------" << setw(2) << "  ";
        gec = gec->sonraki;
        if(gec == 0)
            break;
    }
    cout << endl;
}
void YoneticiListesi::sonrakiyaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    for(int i=0 ; i< 8 ;i++)
    {
        cout << "|" << setw(9) << gec->sonraki << "|" << setw(2) << "  ";

        gec = gec->sonraki;
        if(gec == 0)
            break;
    }
    cout << endl;
}
void YoneticiListesi::oncekiyaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    for(int i=0 ; i< 8 ;i++)
    {
        cout << "|" << setw(9) << gec->onceki << "|" << setw(2) << "  ";

        gec = gec->sonraki;
        if(gec == 0)
            break;
    }
    cout << endl;
}
void YoneticiListesi::ustyaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    if(gec->sonraki == 0 && gec == IlkYoneticiDugum)
    {
        cout << setw(10) << "ilk <-> son" << endl;
        return;
    }
    if(basla != Yldugumsayisi-1)
    {
        if(gec == IlkYoneticiDugum)
            cout << left << setw(13) << "ilk" << right;
        else
            cout << left << setw(13) << "<---"<<right;
        
        gec = gec->sonraki;
            for(int i=0 ; i< 6 ;i++)
            {            
                if(gec->sonraki == 0)
                {
                    break;
                }
                else 
                    cout << setw(13) <<"";
                gec = gec->sonraki;
            }
            if(gec->sonraki == 0)
            {
                cout << setw(10) << "son";
            }
            else
                cout << setw(10) << "--->";
        cout << endl;
    }   
    else
        cout << "<---  son" << endl;
}
void YoneticiListesi::Adresiyaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    for(int i=0 ; i< 8 ;i++)
    {
        cout << "|" << setw(9) << gec << "|" << setw(2) << "  ";

        gec = gec->sonraki;
        if(gec == 0)
            break;
    }
    cout << endl;
}
void YoneticiListesi::ortalamayaz(int basla)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(basla);
    for(int i=0 ; i< 8 ;i++)
    {
        cout << "|" << setw(9) << gec->ortalama << "|" << setw(2) << "  ";
        gec = gec->sonraki;
        if(gec == 0)
            break;
    }
    cout << endl;
}
void YoneticiListesi::SLyazdir(int sira)
{
    Y_L_Dugum* gec = YoneticiDugumGetir(sira);
    gec->S_Liste->SLyazdir(sira);
}
void YoneticiListesi::siralama()
{
    Y_L_Dugum* sonrakininSonraki; //gec->sonraki->sonraki
    Y_L_Dugum* once; //gec->onceki
    Y_L_Dugum* gec;
        for (int i = 0; i < Yldugumsayisi-1; i++)
        {
            gec=IlkYoneticiDugum;
            for (int j = 0; j < Yldugumsayisi-1; j++)
            {

                if ((gec->ortalama) > (gec->sonraki->ortalama))
                {
                    once = gec->onceki;
                    sonrakininSonraki = gec->sonraki->sonraki;
                    gec->sonraki->onceki = once;
                    if(once)
                        once->sonraki = gec->sonraki;
                    else
                        IlkYoneticiDugum = gec->sonraki;
                    gec->sonraki->sonraki = gec;
                    gec->onceki = gec->sonraki;
                    gec->sonraki = sonrakininSonraki;
                    if(sonrakininSonraki)
                        sonrakininSonraki->onceki = gec;
                }
                else
                    gec =gec->sonraki;
                
            }
            
        }
}