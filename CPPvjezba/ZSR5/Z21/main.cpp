//TP 2018/2019: ZSR 5, Zadatak 21
#include <iostream>
#include <vector>

using namespace std;

template<class It, class Neka>

It Nadji( It poc, It kraj, Neka funkcija){
    while(poc!=kraj){
        if (funkcija(*poc)) return poc;
        poc++;
    }
    return kraj;
}

int main(){
     vector <int> v1{1,2,3,4,5,6,7};
     bool cetvorka;
     int i;
     auto it=Nadji(v1.begin(), v1.end(), [](int x){return x==4;});
     while(it!=v1.end()) {
         cout<<*it<<" ";
         it++;
     }
     return 0;
}

