/* 
* @file Dugum.hpp
* @description bir dugum sinifidir.
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
          suhayb.othman@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
    Dugum(int veri);
    int veri;
    Dugum* sonraki;
};

#endif