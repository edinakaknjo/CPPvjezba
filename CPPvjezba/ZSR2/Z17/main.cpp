//TP 2018/2019: ZSR 2, Zadatak 17
#include <iostream>
#include <vector>

using namespace std;

vector<int> Trocifreni(int broj){
    vector<int> trocif;
    for(int i=100; i<1000; i++){
        if (i%broj==0) trocif.push_back(i);
    }
    return trocif;
}
int main ()
{   
    vector<int>trocif;
    int a=95;
    trocif=Trocifreni(a);
    for(int i=0; i<trocif.size(); i++){
        cout<<trocif.at(i)<<" ";
    }
	return 0;
}