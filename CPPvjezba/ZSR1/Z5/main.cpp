//TP 2018/2019: ZSR 1, Zadatak 5
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main ()
{
    cout<<"Unesite koeficijente: ";
    double a, b, c;
    cin>>a;
    cin.ignore(1000,'\n');
    cin>>b;
    cin.ignore(1000,'\n');
    cin>>c;
    cin.ignore(1000,'\n');

    double x1, x2;

    double podkorjenom=pow(b,2)-4*a*c;

    if(c!=0){

    if(podkorjenom>=0){
        double d=sqrt(podkorjenom);
        x1=((-1)*b+d)/(2*a);
        x2=((-1)*b-d)/(2*a);

        cout<<"Rjesenja su :"<<x1<<" i "<<x2<<endl;
    }

    if(podkorjenom<0){
        complex<double> d=sqrt(podkorjenom);
         x1=((-1)*b+real(d)+imag(d))/(2*a);
        x2=((-1)*b-real(d)-imag(d))/(2*a);

        cout<<"Rjesenja su :"<<real(x1)<<"+"<<imag(x1)<<"i i "<<real(x2)<<"+"<< imag(x2)<<"i."<<endl;
    }

    
    }

    else {
        double d=sqrt(podkorjenom);
        x1=((-1)*b+d)/(2*a);
        cout<<"Rjesenje je "<<x1<<".";

    }
	return 0;
}