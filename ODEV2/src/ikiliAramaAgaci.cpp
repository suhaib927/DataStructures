#include <iostream>
#include "IkiliAramaAgaci.hpp"
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = NULL;
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{
    bosaltma(kok);
}
void IkiliAramaAgaci::bosaltma(AgacDugumu* aktif)
{
    if(aktif)
    {
        bosaltma(aktif->sol);
        bosaltma(aktif->sag);
        cikar(aktif->veri);
    }
}
bool IkiliAramaAgaci::varmi(int aranan,AgacDugumu* aktif)
{
    if(aktif->veri < aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        
        return false;
    }
    else if(aktif->veri > aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        
        return false;
    }
    else return true;

}
bool IkiliAramaAgaci::varmi(int veri)
{
    return varmi(veri,kok);
}
void IkiliAramaAgaci::ekle(int veri,AgacDugumu* aktifDugum)
{
    if(kok == NULL)
        kok = new AgacDugumu(veri);
    else if(veri > aktifDugum->veri)
    {
        if(aktifDugum->sag)
            ekle(veri,aktifDugum->sag);
        else
            aktifDugum->sag = new AgacDugumu(veri);
    }
    else if(veri <= aktifDugum->veri)
    {
        if(aktifDugum->sol)
            ekle(veri,aktifDugum->sol);
        else
            aktifDugum->sol = new AgacDugumu(veri);
    }
    else return; 
}
void IkiliAramaAgaci::ekle(int veri)
{
    ekle(veri,kok);
}
int IkiliAramaAgaci::yukseklik(AgacDugumu* aktidfDugum)
{
    if(aktidfDugum)
    {
        return 1+max(yukseklik(aktidfDugum->sol) , yukseklik(aktidfDugum->sag));
    }
    return -1;
}
void IkiliAramaAgaci::cikar(int aranan)
{
    cikar(aranan,kok);
}
void IkiliAramaAgaci::cikar(int aranan,AgacDugumu* &aktif)
{
    if(aktif == NULL)
        return;
    
    if(aktif->veri > aranan)
        cikar(aranan,aktif->sol);
    else if(aktif->veri < aranan)
        cikar(aranan,aktif->sag);
    else
    {
        if(aktif->sag && aktif->sol)
        {
            aktif->veri = enBuyuk(aktif->sol);
            cikar(aktif->veri,aktif->sol);
        }
        else
        {
            AgacDugumu* silinecek = aktif;
            if(aktif->sol == NULL && aktif->sag == NULL)
                aktif = NULL;
            else if(aktif->sag == NULL)
                aktif =aktif->sol;
            else
                aktif = aktif->sag;
            delete silinecek;
        }
    }
}
int IkiliAramaAgaci::enBuyuk(AgacDugumu* aktif)
{
    if(aktif->sag)
        return enBuyuk(aktif->sag);

    return aktif->veri;
}

void IkiliAramaAgaci::preOrder()
{
    preOrder(kok);
}
void IkiliAramaAgaci::postOrder()
{
    postOrder(kok);
}
void IkiliAramaAgaci::inOrder()
{
    inOrder(kok);
}
void IkiliAramaAgaci::preOrder(AgacDugumu* aktif)
{
    if(aktif)
    {
        cout << aktif->veri << "  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}
void IkiliAramaAgaci::postOrder(AgacDugumu* aktif)
{
    if(aktif)
    {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout << aktif->veri << "  ";
    }
}
void IkiliAramaAgaci::inOrder(AgacDugumu* aktif)
{
    if(aktif)
    {
        inOrder(aktif->sol);
        cout << aktif->veri << "  ";
        inOrder(aktif->sag);
    }
}
bool IkiliAramaAgaci::dengelimi()
{
    if(abs(yukseklik(kok->sol) - yukseklik(kok->sag)) > 1)
	    return false;
    else
        return true;
}

