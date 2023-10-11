//TP 2018/2019: ZSR 3, Zadatak 7
#include <iostream>
#include <vector>

using namespace std;

double Suma(vector<int> brojevi){
    double suma=0;
    double jedan=1;
    for(int i=0; i<brojevi.size(); i++){
        int djeljitelj=0;
        for(int j=0; j<=i; j++){
            djeljitelj+=brojevi.at(j);
        }
        if(djeljitelj==0) throw domain_error("Ne moze djeljenje s 0");
        suma+=(jedan/djeljitelj);
    }
    return suma;
}

int main ()
{
    vector<int> v{3, 6,7,5,2,3};
    cout<<Suma(v);
	return 0;
}