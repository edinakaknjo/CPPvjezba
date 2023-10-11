//TP 2018/2019: ZSR 5, Zadatak 41
#include <iostream>
#include <iostream>
#include <complex>
#include <algorithm>
#include <deque>

using namespace std;

void Sortiraj (deque<complex<double>> &dek){
    sort(dek.begin(),dek.end(), []( complex<double> x, complex<double> y){
        if(x.real()<y.real()) return x.real()<y.real();
        if(x.real()==y.real()){
            if(x.imag()<y.imag()) return x.imag()<y.imag();
            else return y.imag()<x.imag();
        }
        return y.real()<x.real();
    });
}

int main ()
{
    deque<complex<double>> dek={{1,2},{1,1}, {4,8}};
    Sortiraj(dek);
    for(int i=0; i<3; i++){
        cout<<dek.at(i);
    }
	return 0;
}