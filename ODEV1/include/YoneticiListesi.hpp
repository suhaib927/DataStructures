#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "SatirListe.hpp"
#include "Y_L_Dugum.hpp"
#include <string>

class YoneticiListesi
{
public:
    YoneticiListesi();// kurucu fonksiyon
    ~YoneticiListesi();// yikici fonkdiyon


    void basla(); // program ilk calistiginda ilk calisan fonksiyon ve bu fonksiyonla kullanici dugmeleri istedigi gibi calistirir
    void YLsil(int sira); //Yonetici dugum sil
    void SLsil(int sira); //Listeden rastgele bir ogeyi silmek icin
    void YLyazdir(int basla); // yonetici listesini yazdirir.
    void SLyazdir(int sira); // SatirListesini yazdirir.
    int Yldugumsayisi=0; // Yonetici listesinin dugum sayisi 
private:
    void YoneticiEkle(string satir); // yeni dugum ekler
    Y_L_Dugum* YoneticiDugumGetir(int sira); // Istenilen dugumun adresini getirir. 
    void siralama(); // bagli listenin dugumleri kucukten buyuguye gore siralanir.
    //yaz
    void ustyaz(int basla); // en ust teki (ilk , ortada bosluk ve aralikta ok isareti , en sonda da SON ) belirten fonksiyon
    void altyaz(int basla); // (--- isareti yazdirir)
    void sonrakiyaz(int basla); // sonraki adresi Yazdirir
    void oncekiyaz(int basla); // onceki adresi Yazdirir.
    void Adresiyaz(int basla); // adresi Yazdirir.
    void ortalamayaz(int basla); // ortalamayi yazdirir.

    Y_L_Dugum* IlkYoneticiDugum; // YoneticiListesinin ilk elemanini isaret yapar.
};

#endif