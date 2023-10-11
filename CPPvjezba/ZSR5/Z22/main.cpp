//TP 2018/2019: ZSR 5, Zadatak 22
#include <iostream>
#include <vector>

using namespace std;

template<typename It>

int Prebroji(It poc, It kraj, bool(*funkcija)(int n)){
    int brojac=0;
    while(poc!=kraj){
        if(funkcija(*poc)) brojac++;
        poc++;
    }
    return brojac;
}

int main ()
{
    vector<int> v{2,3,45,6,87,45,2,12,5,6,7,2,0};
    int broj;
    broj=Prebroji(v.begin(), v.end(), [](int i){return i == 87;});
    cout<<broj;
	return 0;
}