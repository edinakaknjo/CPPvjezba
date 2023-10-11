//TP 2020/2021: Tutorijal 2, Zadatak 3
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;


int main ()
{   
    int n;
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    cout<<endl;
    complex<double> Z, imp(0,0);
    for(int i=1;i<=n;i++){
        cout<<"Z_"<<i<<" = ";
        cin>>Z;
    
        imp+=1./Z;
    }
    imp=1./imp;
    cout<<endl<<"Paralelna veza ovih elemenata ima impedansu Z_ = "<<imp <<".";

    return 0;
}
