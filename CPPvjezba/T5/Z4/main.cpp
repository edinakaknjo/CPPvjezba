
#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <string>

using namespace std;

int main ()
{
    int n;
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    deque<int> dek(n);
    cout<<"Unesite elemente: ";
    
    auto it1(dek.begin()), it2(dek.end());
    for_each(it1, it2, [](int &x){
        cin>>x;
    });

    cout<<"Najveci element deka je "<<*max_element(it1, it2)<<endl;
    int najmanji=*min_element(it1, it2);
    cout<<"Najmanji element deka se pojavljuje "<<count(it1, it2, najmanji)<<" puta u deku"<<endl;
    cout<<"U deku ima "<< count_if(it1, it2, [](int x){
        return sqrt(x)==int(sqrt(x));
    })<<" brojeva koji su potpuni kvadrati"<<endl;
    cout<<"Prvi element sa najmanjim brojem cifara je "<<*min_element(it1, it2, [](int br1, int br2){
         br1=abs(br1);
        br2=abs(br2);
        string cif1=to_string(br1);
        string cif2=to_string(br2);
        return cif1.size()<cif2.size();
    })<<endl;

    deque<int>dekbez3(n);
    auto it3(remove_copy_if(it1, it2, dekbez3.begin(), [](int x){
        return (x>99 && x<1000 || x<(-99) && x>(-1000));
    }));

    dekbez3.resize(it3-dekbez3.begin());
    cout<<"Elementi koji nisu trocifreni su: ";
    for_each(dekbez3.begin(), dekbez3.end(), [](int x){
        cout<<x<<" ";
    });
    cout<<endl;

	return 0;
}