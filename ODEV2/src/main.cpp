#include <iostream> 
#include "TestProgram.hpp"
using namespace std;

int main()
{
    // sil  ------------------------------
    string x;//                          -
    cout << "(1) \n(2) \n(3)\nsec :";//  -
    cin >> x;//                          -
    if(x == "1")//                       -
        x = "Veri.txt";//                -
    else if(x == "2") //                 -
        x = "Veri2.txt";//               -
    else if(x == "3")//                  -
        x = "Data.txt";//                -
    else //                              -
        return 0;//                      -
    //      ------------------------------
    TestProgram* test =new TestProgram(x);
    test->calistir();
    delete test;

    system("pause");
    return 0;
}