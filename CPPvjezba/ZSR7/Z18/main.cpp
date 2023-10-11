//TP 2018/2019: ZSR 7, Zadatak 18
#include <iostream>
#include <list>

using namespace std;

template<typename NekiTip>

bool JeLiSimetricna(list<NekiTip> l){
    
    auto itpomocna=--l.end();
    
    for(auto it2=l.begin(); it2!=l.end(); it2++){
        
        if(*it2!=*itpomocna) return false;
        itpomocna--;

    }

    return true;
}

int main ()
{
    list<int> lista{1,2,3,4,5,4,3,7,1};
    cout<<boolalpha<<JeLiSimetricna(lista);
	return 0;
}