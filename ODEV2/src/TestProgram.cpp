#include "TestProgram.hpp"
#include "Doku.hpp"
#include "Organ.hpp"
#include "Sistem.hpp"
#include "Organizma.hpp"
#include "Kontrol.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
TestProgram::TestProgram(string txtDosayninAdresi)
{
    ifstream file (txtDosayninAdresi);
    string satir;
    Doku* doku;
    Organ* organ = new Organ;
    organizma->ilkSistem = new Sistem;
    Sistem* aktifSistem;
    unsigned short OrganSayisi = 0;
    unsigned short satirsayisi = 1;
    while(getline(file,satir)) 
    {
        doku = new Doku(satir);
        organ->ekle(doku->OrtaHucreGetir());
        delete doku;
        if (satirsayisi == 1) 
        {
            aktifSistem = organizma->ilkSistem;
        }
        else if((satirsayisi-1)%2000 == 0) // Sistem tamamladikca gerceklesme islemi
        {
            aktifSistem->sonraki = new Sistem;
            aktifSistem = aktifSistem->sonraki;
            OrganSayisi = 0;
        }

        if((satirsayisi)%20 == 0)  // organi tamamladikca gerceklesme islemi
        {
            if(organ->OrganAgaci->dengelimi())
            {
                aktifSistem->kontrol[OrganSayisi] = false;
                aktifSistem->kontrolMutasyon[OrganSayisi] = false;
            }
            else
            {
                aktifSistem->kontrol[OrganSayisi] = true;
                aktifSistem->kontrolMutasyon[OrganSayisi] = true;
            }
            
            if(organ->kokunVerisiGetir() % 50 == 0) // mutasyon kontrol etme islemi
            {
                Kontrol* kontrol = new Kontrol(organ->OrganAgaci);
                if(!aktifSistem->kontrol[OrganSayisi])
                    aktifSistem->kontrolMutasyon[OrganSayisi] = true;
                
                delete kontrol;
            }
            delete organ;
            OrganSayisi++;
            organ = new Organ;
        }
        satirsayisi++;
    }
}
TestProgram::~TestProgram()
{
    delete organizma;
}
void TestProgram::calistir()
{
    organizma->yazdir();
}