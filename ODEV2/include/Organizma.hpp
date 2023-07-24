/*
* @file Organizma.hpp
* @description ilk sisteme isaret eden pointer iceriyor onun sayesinde tum sistemlere ulasabiliriz ve yazdirma fonksiyonu icerir  .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef Organizma_hpp
#define Organizma_hpp
#include "Sistem.hpp"
class Organizma
{
public:
    Organizma();
    ~Organizma();
    Sistem* ilkSistem; //ilk sistemi tutacak 
    void yazdir();
};
#endif