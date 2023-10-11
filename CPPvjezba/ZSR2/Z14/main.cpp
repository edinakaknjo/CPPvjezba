//TP 2018/2019: ZSR 2, Zadatak 14
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Djelioci(int br){
    vector<int>djele;
    for(int i=1; i<sqrt(br); i++){
        if(br%i==0) djele.push_back(i);
    }
    return djele;
}

int main ()
{   
    vector<int> djelioci=Djelioci(77);
    for(int i=0; i<djelioci.size(); i++){
        cout<<djelioci.at(i)<<" ";
    }
	return 0;
}