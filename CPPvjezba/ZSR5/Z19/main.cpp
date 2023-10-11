//TP 2018/2019: ZSR 5, Zadatak 19
#include <iostream>
#include <cmath>

using namespace std;

double Simpson( double(*funk)(double), int a, int b, int n){
    double integral=0;
    int h;
    h=(a-b)/n;
    double sume1=0;
    for(int k=1; k<=n-1; k+=2){
        sume1+=funk(a+k*h);
    }

    integral+=4*sume1;

    double sume2=0;
    for(int k=2; k<=n-2; k+=2){
        sume2+=funk(a+k*h);
    }

    integral+=sume2*2;

    integral+=funk(a)+funk(b);

    integral=integral*h/3;

    return integral;
}

double funkcija(double x){
    x=2;
    double kub=x*x*x;
    return kub;
}

int main ()
{
    double x=2;
    cout<<Simpson(funkcija, 0,10, 4);

	return 0;
}