/* 
* @file Doku.hpp
* @description satirin icindeki rakamlari alip ve bu rakamlari hucrelere donusturuyor.
                 kucukten buyuge hucreleri sıraliyor ve ortadaki unsuru donduruyor .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
          suhayb.othman@ogr.sakarya.edu.tr
*/

#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
#include <iostream>
#include <string> 

class Doku
{
public:
    Doku(std::string satir);
    ~Doku();
    int OrtaHucreGetir(); //kucukten buyuge siralidiktan sonra ortadaki hucreyi dondurecek 
    

private:
    Hucre* ilkHucre; //ilk hucreyi tutacak 
    int Hucrelersayisi = 0;
};

#endif