//TP 2020/2021: Tutorijal 2, Zadatak 4
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main ()
{   
    int n;
    double R,X;
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    cout<<endl;
    complex<double>  imp(0,0);
    for(int i=1;i<=n;i++){
        cout<<"R"<<i<<" = ";
        cin>>R;
        cout<<"X"<<i<<" = ";
        cin>>X;
        cout<<endl;
        complex<double>Z(R,X);
        imp+=1./Z;
    }
    imp=1./imp;
    cout<<"Paralelna veza ovih elemenata ima R = "<<real(imp) <<" i X = "<<imag(imp)<<".";

    return 0;
}
