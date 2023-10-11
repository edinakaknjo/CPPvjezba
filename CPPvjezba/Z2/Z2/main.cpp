//TP 2018/2019: Zadaća 2, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

constexpr double epsilon=0.0000001;

bool JeLiKvadrat(int n){
    if(n==0) return true;
    double korjen;
    korjen=sqrt(n);
    if(korjen-int(korjen)<epsilon) return true;
    else return false;

}

int SumaCetiriKvadrata(int n, int &a,int &b, int &c, int &d){
    if(n<0) throw domain_error("Broj koji se rastavlja mora biti nenegativan");

    int pom=n;
    
    int el=sqrt(n);

    if(el*el==n){
        a=el;
        b=0;
        c=0;
        d=0;
    }
    else{
        for(int i=sqrt(n/4); i*i<=n; i++){
            int n1=n-i*i;
            for(int j=sqrt(n1/3); j<=i && j*j<=n1; j++){
                int n2=n1-j*j;
                for(int k=sqrt(n2/2); k<=j && k*k<=n2; k++){
                    int n3=sqrt(n2-k*k);
                    if(n3<=k && n3*n3==n2-k*k){
                        a=i;
                        b=j;
                        c=k;
                        d=n3;
                    }
                }
            }
        }
    }
    return pom;

}

int main ()
{   
    try{
        cout<<"Unesite broj: ";
        int n;
        cin>>n;
        int a, b, c, d;
        int pom=SumaCetiriKvadrata(n, a, b, c, d);
        cout<<"Broj "<<pom<<" se moze zapisati kao zbir kvadrata brojeva: "<<a<<", "<<b<<", "<<c<<", "<<d<<".";
    }
    catch(domain_error e){
        cout<<e.what();
    }
	return 0;
}