#ifndef S_L_Dugum_hpp
#define S_L_Dugum_hpp
using namespace std;

class S_L_Dugum
{
public:
    S_L_Dugum(int veri)
    {
        this->veri = veri;
        this->sonraki = 0;
        this->onceki = 0;
    }
    //  SatirListesi icin cift yonlu bagli liste bilgileri.
    int veri;
    S_L_Dugum* sonraki;
    S_L_Dugum* onceki;
};
#endif