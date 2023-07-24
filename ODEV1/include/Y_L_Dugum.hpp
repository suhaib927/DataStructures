#ifndef Y_L_Dugum_hpp
#define Y_L_Dugum_hpp
#include "SatirListe.hpp"
class Y_L_Dugum
{
public:
    Y_L_Dugum()
    {
        this->sonraki = 0;
        this->onceki = 0;
        this->S_Liste =0;
        this->ortalama = 0;
    }
    ~Y_L_Dugum()
    {
        delete S_Liste;
    }
    // YoneticiListesi icin cift yonlu bagli liste bilgileri.
    Y_L_Dugum* sonraki;
    Y_L_Dugum* onceki;
    // SatirListesi turunden bir isaretci ve onun gorevi Satir Listesindeki elemnalari isaret yapar
    SatirListe* S_Liste;
    // SatirListenin elemanlarin ortalamasi burda saklanir
    float ortalama;
};
#endif