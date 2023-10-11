//TP 2018/2019: ZSR 5, Zadatak 44
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int BrojDJelilaca(int n){
    int brojac=0;
    while(n!=0){
        brojac++;
        n/=10;
    }
    return brojac;
}
bool Kriterij(int x, int y){
    
    int brdj1=BrojDjelilaca(x);
    int brdj2=BrojDjelilaca(y);
    if(brdj1>brdj2) return x<y;
    if(brdj1==brdj2){
        if(x<y) return x<y;
        else return y<x;
    }
}

void sortirajpoBrojuDjelioca(deque<int> &dek){
    sort(dek.begin(), dek.end(), Kriterij);
}

int main ()
{
    deque<int> dek{3,10,5,67,12,9};
    sortirajpoBrojuDjelioca(dek);
    for(int i=0; i<dek.size(); i++){
        cout<<dek.at(i)<<" ";
    }
	return 0;
}