//TP 2018/2019: ZSR 7, Zadatak 22
#include <iostream>
#include <vector>

using namespace std;

template<typename it1, typename it2, typename fun>

auto PopuniPoKriteriju( it1 p1, it1 p2, it2 p3, it2 &p4, fun f)->typename std::remove_reference<decltype (*p1)>::type {
    
     typedef typename std::remove_reference<decltype (*p1)>::type prvitip;

    prvitip rezultat{};
    while(p1!=p2){
        *p3=f(*p1);
        p1++;
        p3++;
        rezultat+=*p1;
    }
    p4=p3;

    return rezultat;
}

int main ()
{
    vector<int>v1{1,2,3,4,5};
    vector <int>v2(v1.size());
    vector<int>::iterator izakraja;
    PopuniPoKriteriju(v1.begin(), v1.end(), v2.begin(), izakraja, [](int broj){
        broj+=10;
        return broj;
    } );
    for(auto it=v2.begin();it!=izakraja; it++){
        cout<<*it<<" ";
    }
	return 0;
}