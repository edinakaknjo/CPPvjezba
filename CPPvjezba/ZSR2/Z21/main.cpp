//TP 2018/2019: ZSR 2, Zadatak 21
#include <iostream>
#include <vector>

using namespace std;

int Najmanjacif(int broj){
    int najmanja=9;
    while(broj!=0){
        int cif;
        cif=broj%10;
        if (cif<najmanja) najmanja=cif;
        broj/=10;
    }
    return najmanja;
}

vector<int> veknajmanjih(vector<int> v){
    vector<int> cifre;
    for(int i=0; i<v.size(); i++){
        int cif=Najmanjacif(v.at(i));
        cifre.push_back(cif);
    }
    return cifre;
}

int main ()
{
    vector<int> v1{32, 4 , 72, 8, 24, 771};
    vector<int> najmanji=veknajmanjih(v1);
    for(int i=0; i<najmanji.size(); i++){
        cout<<najmanji.at(i)<<" ";
    }
	return 0;
}