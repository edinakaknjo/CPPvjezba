//TP 2018/2019: ZSR 2, Zadatak 36
#include <iostream>
#include <vector>

using namespace std;


int SumaCif(int broj){
    int suma=0;
    while(broj!=0){
        suma+=(broj%10);
        broj/=10;
    }
    return suma;
}

vector <int> Brojevidjeljivisumom(int n){
    vector<int>brdjeljivi;
    for(int i=1; i<n; i++){
        if(i%SumaCif(i)==0) brdjeljivi.push_back(i);
    }
    return brdjeljivi;
}

int main ()
{   
    vector<int> v;
    v=Brojevidjeljivisumom(25);
    
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<", ";
    }
   
	return 0;
}