//TP 2018/2019: ZSR 2, Zadatak 28
#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> Logvr(vector<int> brojevi){

    int brojel=brojevi.size();

    vector<bool> dalijeprost(brojel);

    for(int i=0; i<brojevi.size(); i++){
        int broj=brojevi.at(i);
        dalijeprost.at(i)=true;
        for(int j=2; j<=broj/2; j++){
            if(broj%j==0) dalijeprost.at(i)=false;
            
            }
        }
        
    
    return dalijeprost;
}

int main ()
{
    vector<int> brojevi{15,11,45,9,14,3,300};
    vector<bool>v=Logvr(brojevi);
    int i=0;
    while(i!=v.size()){
        cout<<v.at(i)<<" ";
        i++;
    }
	return 0;
}