//TP 2018/2019: ZSR 4, Zadatak 39
#include <iostream>
#include <vector>

using namespace std;

void DodajSuprotne(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        int suprotan=v.at(i)*(-1);
        v.insert(v.begin()+i, suprotan);
        i++;
    }
}

int main ()
{
    vector<int> v{3,45,2,-97};
    DodajSuprotne(v);
    int i=0;
    for(int i=0; i<v.size(); i++){
        cout<<v.at(i)<<" ";
    }
	return 0;
}