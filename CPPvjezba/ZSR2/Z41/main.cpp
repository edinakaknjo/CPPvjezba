//TP 2018/2019: ZSR 2, Zadatak 41
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool JeLiArmstrongov(int n){
    int broj=0;
    while(n!=0){
        int cif=n%10;
        broj+=(cif*cif*cif);
        n/=10;
    }
    if(broj==n) return true;
    return false;
}

vector<int> Armstrongovi( int p, int q){
    vector<int> brojevi;
    for(int i=p; i<q; i++){
        if (JeLiArmstrongov(i)) brojevi.push_back(i);
        
    }
    return brojevi;
}

int main ()
{
    vector<int> brojevi;
    brojevi=Armstrongovi(150, 155);
    for(int i=0; i<brojevi.size(); i++){
        cout<<brojevi.at(i)<<" ";
    }
	return 0;
}