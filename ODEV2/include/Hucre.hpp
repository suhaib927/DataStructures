/* 
* @file Hucre.hpp
* @description hucreninin degerini iceriyor , ve pointer 'sonraki' sonraki hucreye ulasmak icin   .
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
        suhayb.othman@ogr.sakarya.edu.tr
*/
#ifndef Hucre_hpp
#define Hucre_hpp
class Hucre
{
public:
    Hucre(int veri)
    {
        this->veri = veri;
        sonraki = 0;
    }
    int veri;
    Hucre* sonraki;
};
#endif