//TP 2018/2019: ZSR 5, Zadatak 33
#include <iostream>
#include <vector>

using namespace std;

template<typename T>

vector<T> Funkcija(T x, T (*funk)(T), int n){
    vector<T> vraceni;
    for(int i=0; i<n; i++){
        x=(*funk)(x);
        vraceni.push_back(x);
    }

    return vraceni;
}

int pomocna(int br){
    int broj=br+10;
    return broj;
}

int main ()
{
    int x=2;
    vector<int> vraceni= Funkcija(x,pomocna, 5);
    for(int i=0; i<vraceni.size(); i++){
        cout<<vraceni.at(i)<<" ";
    }

	return 0;
}