/*
* @file Sistem.hpp
* @description iki dizi iceriyor , dengeli olup olmadigini 100 kontrol etme islemi iceriyor   .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef Sistem_hpp
#define Sistem_hpp

class Sistem
{
public:
    Sistem()
    {
        this->sonraki = 0;
    }
    bool kontrol[100]; // oragani dengeli olup olmadigini kontrol edecek ve sonuc dizide depolanacak 

    bool kontrolMutasyon[100]; //mutasyon dengeli olup olmadigini kongtrol edecek ve sonuc dizide depolanacak 
    Sistem* sonraki;
};
#endif