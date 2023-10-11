//TP 2018/2019: ZSR 5, Zadatak 10
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template<typename It>

    void Najmanji( It niz, int brojel, int &najmanji, int &drnajmanji ){
    
    int i=0;
    najmanji=*niz;
    niz++;
    drnajmanji=*niz;
    niz--;
    int pomocna=najmanji;
    if(drnajmanji<najmanji){
        najmanji=drnajmanji;
        drnajmanji=pomocna;
    }

    while(niz+1!=niz+brojel){
        if(*niz<najmanji && *niz<drnajmanji) najmanji=*niz;
        if(*(niz+1)<drnajmanji && *(niz+1)>najmanji) drnajmanji=*(niz+1);
        niz++;
    }
}



int main ()
{
    int a=0, b=0;
    vector<int> v{56,4,3,8,2,56};
    Najmanji(v.begin(),6,a,b);
    cout<<a<<" "<<b;
	return 0;
}