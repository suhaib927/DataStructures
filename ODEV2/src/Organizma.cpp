#include "Organizma.hpp"
#include <iomanip> 
#include <iostream>
using namespace std;

Organizma::Organizma()
{
    ilkSistem = 0;
}
Organizma::~Organizma()
{
    Sistem* sil;
    while(ilkSistem)
    {
        sil = ilkSistem;
        ilkSistem = ilkSistem->sonraki;
        delete sil;
    }
}
void Organizma::yazdir()
{
    Sistem* gec = ilkSistem;
    system("cls");
    cout << setw(32) << "" << "ORGANIZMA" << endl; 
    while(gec)
    {
        for(int i = 0 ; i < 100 ;i++)
        {
            if(gec->kontrol[i])
                cout << "#";
            else 
                cout << " ";
        }
        cout << endl;
        gec = gec->sonraki;
    }
    system("pause");
    system("cls");
    gec = ilkSistem;
    cout << setw(24) << "" << "ORGANIZMA (MUTASYON UGRADI)" << endl;
    while(gec)
    {
        for(int i = 0 ; i < 100 ;i++)
        {
            if(gec->kontrolMutasyon[i])
                cout << "#";
            else 
                cout << " ";
        }
        cout << endl;
        gec = gec->sonraki;
    }
}