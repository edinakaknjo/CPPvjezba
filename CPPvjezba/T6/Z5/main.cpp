
#include <iostream>
#include <vector>
#include <deque>
#include <new>
#include <string>
#include <type_traits>
#include <stdexcept>
 

using namespace std;
template<typename TipMat>

auto KreirajDinamickuKopiju2D (TipMat matrica) -> typename remove_reference<decltype(matrica[0][0])>::type** {
    typedef typename remove_reference<decltype(matrica[0][0])>::type matTip;
    matTip** rezultat=new matTip*[matrica.size()]{};

    try{
        for(int i=0; i<matrica.size(); i++){
            rezultat[i]=new matTip[matrica[i].size()];
            for(int j=0; j<matrica[i].size(); j++){
                rezultat[i][j]=matrica[i][j];
            }
        }
    }
    catch(bad_alloc){
        for(int i=0; i<matrica.size();i++) delete[] rezultat[i];
        delete[] rezultat;
        throw;
    }
    return rezultat;
}
int main ()
{
    try{
    cout<<"Unesite broj redova kvadratne matrice: ";
    int n;
    cin>>n;
    vector<deque<int>> Vektordekova(n);
    cout<<"Unesite elemente matrice: ";
    for(int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            int el;
            cin>>el;
            Vektordekova.at(i).push_back(el);
        }
    }
         int **pok(KreirajDinamickuKopiju2D(Vektordekova));
             for(int i=0; i<n;i++){
                 for (int j=0; j<n; j++){
                     cout<<pok[i][j]<<" ";
                 }
             cout<<endl;}
         
        for(int i=0; i<Vektordekova.size();i++) delete[] pok[i];
         delete[] pok;

    }
    catch(bad_alloc){
             cout<<"Nedovoljno memorije"<<endl;
    }
    
	return 0;
}