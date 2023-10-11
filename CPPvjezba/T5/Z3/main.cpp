
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

constexpr double epsilon=0.0000000001;

bool PotpunKvadrat(int br){
    double korjen;
    if(br<0) return false;
    else{
        br=abs(br);
        korjen=sqrt(br);
        if(korjen-int(korjen)<epsilon) return true;
        else return false;
    }
}

bool NijeTrocif(int n){
    n=abs(n);
    string brcif= to_string(n);
    if(brcif.size()==3) return true;
    else return false;
}

bool NajmanjeCif(int br1, int br2){
    br1=abs(br1);
    br2=abs(br2);
    string cif1=to_string(br1);
    string cif2=to_string(br2);
    return cif1.size()<cif2.size();

}

void unos(int &el){
    cin>>el;
}
void ispis(int el){
    cout<<el<<" ";
}

int main ()
{   
    int niz[1000];
    int n;
    cout<<"Unesite broj elemenata (max. 1000): ",
    cin>>n;
    cout<<"Unesite elemente: ";
    for_each(niz, niz+n, unos);

    cout<<"Najveci element niza je "<<*max_element(niz, niz+n)<<" "<<endl;
    int najmanji=*min_element(niz, niz+n);
    cout<<"Najmanji element niza se pojavljuje "<<count(niz, niz+n, najmanji)<<" puta u nizu"<<endl;
    cout<<"U nizu ima "<<count_if(niz, niz+n, PotpunKvadrat)<<" brojeva koji su potpuni kvadrati"<<endl;
    cout<<"Prvi element sa najmanjim brojem cifara je "<<*min_element(niz, niz+n, NajmanjeCif)<<endl;

    int nizbeztrocif[1000];
    transform(niz,niz+n, nizbeztrocif, NijeTrocif);
    int *kraj=remove_copy_if(niz, niz+n, nizbeztrocif, NijeTrocif);
    cout<<"Elementi koji nisu trocifreni su: ";
    for_each(nizbeztrocif, kraj, ispis);
	return 0;
}