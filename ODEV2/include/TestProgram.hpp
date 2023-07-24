/*
* @file TestProgram.hpp
* @description dosyanin kaynagi aliyor ve okuma islemi yapiyor ve gorevler siniflara daigitiyor  .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef TestProgram_hpp
#define TestProgram_hpp
#include <iostream>
#include "Organizma.hpp"
using namespace std;

class TestProgram
{   
public:
    TestProgram(string txtDosayninAdresi);
    ~TestProgram();
    void calistir();
private:
    Organizma* organizma = new Organizma;
};

#endif