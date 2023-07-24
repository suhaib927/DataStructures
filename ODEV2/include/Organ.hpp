/*
* @file Organ.hpp
* @description doku degerleri tasıyan agac olusturuyor , ve kokun verisi donduren fonksiyonu iceriyor  .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.hpp"
#include "ikiliAramaAgaci.hpp"

class Organ
{
public:
    Organ();
    ~Organ();
    void ekle(int veri);
    int kokunVerisiGetir();
    IkiliAramaAgaci* OrganAgaci;
};
#endif