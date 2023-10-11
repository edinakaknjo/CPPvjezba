//TP 2018/2019: ZSR 5, Zadatak 20
#include <iostream>
#include <array>
#include <vector>

using namespace std;

template<class Pok, class It>

bool JednakiBlokovi(Pok pocetak1, Pok kraj1, It pocetak2){
    while(pocetak1!=kraj1){
        if(*pocetak1!=*pocetak2) return false;
        pocetak1++;
        pocetak2++;
    }
    return true;

}

int main(){
    vector<int> v1{1,2,3,4,5,6,7};
    vector <int> v2{1,2,3,4,7};
    cout<<JednakiBlokovi(v1.begin(), v1.end(), v2.begin());

}