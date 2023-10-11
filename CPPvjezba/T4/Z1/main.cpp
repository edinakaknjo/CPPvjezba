//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

using namespace std;

int Cifre(long long int n, int &c_min, int &c_max){
    int brcif=0;

    c_max=0;
    c_min=9;

    if(n==0){
        c_max=0;
        c_min=0;
        brcif=1;
    }
    else{
        while(n!=0){
            int cif=n%10;
            if(cif<0){cif*=(-1);}
            if(cif>c_max) c_max=cif;
            if(cif<c_min) c_min=cif;
            n/=10;
            brcif++;
        }
    }
  
    return brcif;
}
int main ()
{
    int a,c;
    long long int n;

    cout<<"Unesite broj: ";
    cin>>n;

    int cif=Cifre(n,a,c);
    
    cout<<"Broj "<<n<<" ima "<<cif;
    cout<<" cifara, najveca je "<<c<<" a najmanja "<<a<<"."<<endl;
	return 0;
}