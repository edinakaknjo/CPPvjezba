#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double TrapeznoPravilo(double (*fun)(double),double a, double b, int n){
    double sum=0;
    for(int i=1; i<n; i++){
        sum+=fun(a+((b-a)*i/n));
    }
    return ((b-a)/n)*(0.5*fun(a)+0.5*fun(b)+sum);
}

int main ()
{   
    cout<<"Unesite broj podintervala: ";
    int br;
    cin>>br;
    cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: "<<endl;
    cout<<"- Za funkciju sin x na intervalu (0,pi): "<<fixed<<setprecision(5)<<TrapeznoPravilo(sin, 0, atan(1)*4, br)<<endl;
    cout<<"- Za funkciju x^3 na intervalu (0,10): "<<fixed<<setprecision(2)<<TrapeznoPravilo([](double x){return x*x*x;}, 0, 10, br)<<endl;
    cout<<"- Za funkciju 1/x na intervalu (1,2): "<<fixed<<setprecision(5)<<TrapeznoPravilo([](double x){return 1/x;},1,2,br)<<endl;
	return 0;
}