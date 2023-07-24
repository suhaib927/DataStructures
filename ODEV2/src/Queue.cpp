#include "Queue.hpp"
#include <iomanip>
#include<stdexcept>
Queue::Queue()
{
    ilk=son=0;
    elemanSayisi=0;
}
Queue::~Queue()
{
    while(ilk!=0)
    {
        Dugum*gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}
bool Queue::bosmu()
{
    if(ilk==0)
        return true;
    return false;
}

void Queue::ekle(int veri)
{
    if(ilk==0)
    {
        ilk=new Dugum(veri);
        son= ilk;

    }
    else
    {
        Dugum*yeni = new Dugum(veri);
        son->sonraki = yeni;
        son = yeni;

    }
    elemanSayisi++;
}
void Queue::cikar()
{
    if(ilk!=0)
    {
        Dugum*gec = ilk->sonraki;
        delete ilk;
        ilk=gec;
        if(ilk==0)
            son=0;
        elemanSayisi--;
    }
}
int Queue::getir()
{
    if(ilk!=0)
        return ilk->veri;
    throw std::out_of_range("Queue Bos");
}

int Queue::elemanSayisiGetir()
{
    return elemanSayisi;
}
ostream& operator<<(ostream& os,Queue& Queue)
{
    if(Queue.ilk==0)
        os<<"----Queue BOS----";
    Dugum*gec= Queue.ilk;
    while(gec!=0)
    {
        os<<setw(5)<<gec->veri;
        gec = gec->sonraki;  
    }

    os<<endl; 
    return os;
}