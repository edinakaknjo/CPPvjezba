//TP 2018/2019: ZSR 7, Zadatak 33
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;


function<double(double)>Polinom(vector<double> brojevi){

    return [brojevi](double x){
        double rez=0;
        int stepen=0;
        for(int i=0; i<brojevi.size(); i++){
            rez+=(brojevi.at(i)*pow(x,stepen));
            stepen++;
    
        }
        return rez;
    };
}

int main ()
{
    
    auto poli = Polinom({3, 5, 0, 4, 1});
    cout<<poli(2);

	return 0;
}