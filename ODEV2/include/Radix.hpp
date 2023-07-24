/* 
* @file Radix.hpp
* @description dokulari siralamak icin kullandigimiz radixsort sinifidir.
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
          suhayb.othman@ogr.sakarya.edu.tr
*/

#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"
#include "Hucre.hpp"

class Radix
{
public:
    Radix(Hucre *sayilar,int adet);
    ~Radix();
    int* sirala();
private:
    int     maxBasamakSayisiGetir();
    int     basamakSayisiGetir(int sayi);
    void    QueuelariYazdir();
    void    QueueUzunluklariGetir(int* uzunluklar);
    Queue** Queuelar;
    int*    sayilar;
    int     sayiAdedi;
};

#endif