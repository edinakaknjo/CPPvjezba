//TP 2018/2019: ZSR 4, Zadatak 27
#include <iostream>
#include <cmath>

using namespace std;

int OdstraniParne(int el){
    int rez=0;
    int stepenDesetke=1; //10^0
    while(el!=0){
        int cifra=el%10;
        if(cifra%2!=0) {
            rez+=stepenDesetke*cifra;
            stepenDesetke*=10;
        }
        el/=10;
    }
    return rez;
}

int main ()
{
    cout<<OdstraniParne(56796);
	return 0;
}