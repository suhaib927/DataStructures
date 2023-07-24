/*
* @file IkiliAramaAgaci.hpp
* @description  organda kullandigimiz ikili arama agaci sinifi
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include "AgacDugumu.hpp"
class IkiliAramaAgaci
{
public:
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();


    bool varmi(int veri);
    void ekle(int veri);
    void cikar(int aranan);
    bool dengelimi();
    //yazdir
    void preOrder();
    void postOrder();
    void inOrder();
    AgacDugumu* kok;

private:
    void bosaltma(AgacDugumu* aktif);
    bool varmi(int aranan,AgacDugumu* aktif);
    void ekle(int veri,AgacDugumu* aktifDugum);
    void cikar(int aranan,AgacDugumu* &aktif);
    int yukseklik(AgacDugumu* aktidfDugum);
    int enBuyuk(AgacDugumu* aktif);

    //yazdir
    void preOrder(AgacDugumu* aktif);
    void postOrder(AgacDugumu* aktif);
    void inOrder(AgacDugumu* aktif);
};

#endif