#ifndef SatirListe_hpp
#define SatirListe_hpp
#include "S_L_Dugum.hpp"
#include <string>
class SatirListe
{
public:

    SatirListe(string);
    ~SatirListe();
    
    void SL_RastgeleSilme(int sira); // rastgele dugum siler
    float ortalamaGetir(); // SatirListesinin elemanlarini ortalamasini hesaplar
    void SLyazdir(int sira); // SatirListesini Yazdirir
    int SatirDugumSayisi = 0;
private:
    
    S_L_Dugum* SatirDugumGetir(int); // Istenilen dugumun adresini getirir.
    void SatirDugumEkle(int veri); // Satira dugum eklenir.
    //yaz
    void CizgiYaz(int sira); // (--- isareti yazdirir)
    void bosbirak(int sira); // blok bir sekilde bosluk birakan fonksiyon
    S_L_Dugum* IlkSatirDugum; // SatirListesinin ilk elemanini isaret yapar.
};


#endif