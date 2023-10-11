#include <iostream>
#include <new>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <stdexcept>
 
using namespace std;
 
template <typename Iterator>
 
auto KreirajIzvrnutiNiz(Iterator poc, Iterator kraj)->typename std::remove_reference<decltype(*poc)>::type* {
    typedef typename std::remove_reference<decltype(*poc)>::type Povratni;
    Iterator it(poc);
    int velicina=0;
    while(it!=kraj){
        it++;
        velicina++;
    }
 
    Povratni* izvrnuti=new Povratni[velicina];
    try{
        int brojac=0;
        velicina--;
        while(poc!=kraj){
            izvrnuti[velicina-brojac]= *poc++;
            brojac++;
    }
    }
    catch(bad_alloc){
        delete[] izvrnuti;
    }
    return izvrnuti;
}
int main ()
{  
    try{
        cout<<"Koliko zelite elemenata: ";
         int n;
        cin>>n;
        vector<double> v1(n);
        cout<<"Unesite elemente: ";
         for(int i=0; i<n; i++){
             cin>>v1.at(i);
        }
        cout<<"Kreirani niz: ";
 
        auto niz= KreirajIzvrnutiNiz(v1.begin(), v1.end());
        for(int j=0; j<n;j++){
          cout<<niz[j]<<" ";
         }
        delete[] niz;
    }
    catch(bad_alloc){
        cout<<"Nedovoljno memorije!"<<endl;
    }
 
    return 0;}