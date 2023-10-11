//TP 2020/2021: Tutorijal 2, Zadatak 5
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

constexpr double PI=4*atan(1);



int main ()
{   
    int n;
    double R,X;
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    cout<<endl;
    complex<double>  imp(0,0);
    for(int i=1;i<=n;i++){
        cout<<"Z"<<i<<" = ";
        cin>>R;
        cout<<"fi"<<i<<" = ";
        cin>>X;
        cout<<endl;
        complex<double>Z=polar(R,X*PI/180);
        imp+=1./Z;
    }
    imp=1./imp;
    cout<<"Paralelna veza ovih elemenata ima Z = "<<abs(imp) <<" i fi = "<<arg(imp)*180/PI<<".";

    return 0;
}
