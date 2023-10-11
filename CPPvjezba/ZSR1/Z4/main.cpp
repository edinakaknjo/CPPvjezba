//TP 2018/2019: ZSR 1, Zadatak 4
#include <iostream>
using namespace std;

int main ()
{
    double pretp1=0.5, pretp2=0.8;
    cout<<"Unesite broj sati: ";
    int sati;
    cin>> sati;

    double cijena1, cijena2;
    cijena1=10+pretp1*sati;
    cijena2=pretp2*sati;

    if(cijena1<cijena2) cout<<"Jeftinija Vam je 1. firma";
    else cout<<"Jeftinija Vam je 2. firma";

	return 0;
}