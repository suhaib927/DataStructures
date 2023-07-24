#include "Organ.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Organ::Organ()
{
    OrganAgaci = new IkiliAramaAgaci;
}
Organ::~Organ()
{
    delete OrganAgaci;
}
void Organ::ekle(int veri)
{
    OrganAgaci->ekle(veri);
}
int Organ::kokunVerisiGetir()
{
    return OrganAgaci->kok->veri;
}