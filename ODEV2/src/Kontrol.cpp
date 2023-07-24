#include "Kontrol.hpp"
#include <iostream>
using namespace std;
Kontrol::Kontrol(IkiliAramaAgaci* aktifAgac)
{
    this->agac = aktifAgac;
    yariyaDusur(agac->kok);
    OkuPostOrder(agac->kok);
    agac = 0;
    yeniAgacOlustur();
}
Kontrol::~Kontrol()
{
    delete agac;
}
void Kontrol::yeniAgacOlustur()
{
    agac = new IkiliAramaAgaci;
    for(int i =0; i < 20; i++)
    {
        agac->ekle(veriler[i]);
    }
}
bool Kontrol::dengelimi()
{
    return agac->dengelimi();
}
void Kontrol::yariyaDusur(AgacDugumu* &aktif)
{
    if(aktif)
    {
        yariyaDusur(aktif->sol);
        yariyaDusur(aktif->sag);
        if(aktif->veri %2 == 0)
        {
            aktif->veri /= 2;
        }
    }
}
void Kontrol::OkuPostOrder(AgacDugumu* aktif)
{
    if(aktif)
    {
        OkuPostOrder(aktif->sol);
        OkuPostOrder(aktif->sag);
        veriler[verisayisi] = aktif->veri;
        verisayisi++;
    }
}