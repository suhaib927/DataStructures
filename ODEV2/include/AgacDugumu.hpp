/* 
* @file AgacDugumu.hpp
* @description ikili arama agacında kullanılan dugum sinifidir
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
          suhayb.othman@ogr.sakarya.edu.tr
*/

#ifndef AgacDugumu_hpp
#define AgacDugumu_hpp
#include <iostream>
#include <iomanip>
using namespace std;
class AgacDugumu
{
public:
    AgacDugumu(int veri)
    {
        this->veri = veri;
        sol = NULL;
        sag = NULL;
    }
    int veri;
    AgacDugumu* sol;
    AgacDugumu* sag;
};
#endif