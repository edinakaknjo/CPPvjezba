#include <iostream>
#include <vector>
#include <deque>
#include <new>
#include <string>
#include <type_traits>
#include <stdexcept>
 
 
using namespace std;
template<typename TipMat>
 
auto KreirajDinamickuKopiju2D (TipMat matrica)-> decltype(matrica[0][0]+matrica[0][0])** {
    decltype(matrica[0][0]+matrica[0][0])** rezultat= new decltype(matrica[0][0]+matrica[0][0])*[matrica.size()];
    
    try{
        int brojel=0;
        for(int i=0; i<matrica.size(); i++) brojel+=matrica[i].size();
        rezultat[0]= new decltype(matrica[0][0]+matrica[0][0])[brojel];
        for(int i=1; i<matrica.size(); i++) rezultat[i]=rezultat[i-1]+ matrica[i-1].size();
        for(int i=0; i<matrica.size(); i++){
            for(int j=0; j<matrica[i].size(); j++){
                rezultat[i][j]=matrica[i][j];
            }
        }
    }
    catch(bad_alloc){
        /*for(int i=0; i<matrica.size();i++) delete[] rezultat[0];*/
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
             cout<<endl;
         }
    delete[] pok[0];
    delete[] pok;
         }
         catch(bad_alloc){
             
        cout<<"Nedovoljno memorije"<<endl;
         }
    
    return 0;
}
