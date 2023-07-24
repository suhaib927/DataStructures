/* 
* @file Doku.hpp
* @description Radix sortta kullandigimiz kuruk sinifi
* @course 1.ogretim c grubu 
* @assignment 2.odev
* @date 15.12.2022
* @author SUHAYB ALHAS OTHMAN
          suhayb.othman@ogr.sakarya.edu.tr
*/

#ifndef Queue_hpp
#define Queue_hpp
#include<iostream>
#include "Dugum.hpp"
using namespace std;

class Queue
{
public:
	Queue();
	~Queue();
	void ekle(int veri);
	void cikar();
    bool bosmu();
	int getir();
	int elemanSayisiGetir();
    friend ostream& operator<<(ostream& os,Queue& Queue);
private:
	Dugum* 	ilk;
	Dugum*	son;
	int elemanSayisi;
};

#endif