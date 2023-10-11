//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <cmath>

using namespace std;

template<typename BrojcaniTip>

void UnosBroja(string unosni, string greska, BrojcaniTip &br){
    bool tacan;
    do{tacan=true;
    cin.clear();
    cout<<unosni<<endl;
    cin>>br;
    
    if(!cin || cin.peek()!=10){
        cout<<greska<<endl;
        tacan=false;
    }
    
    cin.clear();
    cin.ignore(1000,'\n');}while(!tacan);
}

int main ()
{   
    double br;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...",br);
    int eksponent;
    cout<<endl;
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", eksponent);
    double rez=1, novabaza=br;

    if(eksponent==0){
        rez=1;
    }
    else if(eksponent>0){
        rez*=br;
    }
    else if(eksponent<0){
        novabaza=1/br;
        rez=novabaza;
    }

    for(int i=1; i<abs(eksponent); i++){
        rez*=novabaza;
    }

    cout<<endl<<br<<" na "<<eksponent<<" iznosi "<<rez<<endl;
	return 0;
}