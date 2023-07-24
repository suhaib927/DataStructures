/** 
* @file main.cpp
* @description YoneticiListesi turunden yeni eleman olusturdum ve basla fonksiyonunu cagirdik.
* @course Egitim Turu: 1 ogretim , Grup: c .
* @assignment Odev No: 1.
* @date 17/11/2022
* @author Isim: SUHAYB ALHAS OTHMAN , E POSTA : suhayb.othman@ogr.sakarya.edu.tr , Ogrenci No: B201210560
*/

#include <iostream> 
#include "YoneticiListesi.hpp"
int main()
{
    YoneticiListesi* YeniYonetici =new YoneticiListesi;
    YeniYonetici->basla();

    delete YeniYonetici;
    return 0;
}