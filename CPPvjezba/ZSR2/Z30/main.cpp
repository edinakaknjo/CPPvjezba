//TP 2018/2019: ZSR 2, Zadatak 30
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool JeLiSavrsen(int n){
    int suma=0;
    for(int i=1; i<=n/2; i++){
        if(n%i==0) suma+=i;
    }
    return (suma==n);

}

vector<int> Savrsenibr(vector<int> brojevi){
    vector<int> vraceni;

    for(int i=0; i<brojevi.size(); i++){
        if(JeLiSavrsen(brojevi.at(i))) vraceni.push_back(brojevi.at(i));
    }

    return vraceni;
}


int main ()
{
    vector<int> v{1,2,3,46,74,28,9};
    vector<int> v1=Savrsenibr(v);
    int i=0;
    while(i!=v1.size()){
        cout<<v1.at(i)<<" ";
        i++;
    }
	return 0;
}