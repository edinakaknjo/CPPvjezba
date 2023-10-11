//TP 2018/2019: ZSR 4, Zadatak 37
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsteParnosti(int n){
    vector<int> cifre;
    while(n!=0){
        int cif=abs(n%10);
        cifre.push_back(cif);
        n/=10;
    }

    bool parnostprvog=true;

    if(cifre.at(0)%2==1) parnostprvog=false;

    for(int i=0; i<cifre.size(); i++){
        bool parnostovog=true;
        if(cifre.at(i)%2==1) parnostovog=false;
        if(parnostovog!=parnostprvog) return false;
    }

    return true;
}

void IzbaciIsteParnosti(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        if(IsteParnosti(v.at(i))){
            int index=i;
            v.at(index)=v.at(index+1);
            v.resize(v.size()-1);
        }
    }
}

int main ()
{
    vector<int>v{333,124634,246,12345,765,931};
    IzbaciIsteParnosti(v);
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" ";
    }
	return 0;
}