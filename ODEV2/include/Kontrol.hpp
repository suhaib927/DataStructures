/*
* @file Kontrol.hpp
* @description  mutasyon islemi yapar, cift olan degerleri 2'ye bolunuyor, post order okuma islemi yapar , yeni agac olusturuyor .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "Organ.hpp"
#include "Doku.hpp"
#include "ikiliAramaAgaci.hpp"
#include "AgacDugumu.hpp"
class Kontrol
{
public:
    Kontrol(IkiliAramaAgaci* aktifagac);
    ~Kontrol();
    bool dengelimi(); // organ dengeliyse false dondurecek, degilse true dondurecek
private:
    IkiliAramaAgaci* agac;
    void yariyaDusur(AgacDugumu* &aktif); //agacin icindeki cifli unsurlari 2'ye bolunecek 
    void OkuPostOrder(AgacDugumu* aktif); //  agaci, post order yardimiyla okunacak , ve veriler dizinde depolanacak
    void yeniAgacOlustur();
    int veriler[20];
    int verisayisi = 0;
};

#endif