//TP 2018/2019: Zadaća 2, Zadatak 4
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;



int BrojDjelioca(int n){
    int i=1, brojac=0;
    while(i<=sqrt(n))
         {
          if(n%i==0)
           {
            brojac++;
             if(i!=(n/i))
              brojac++;
           }
          i++; 
         }
        return brojac;
}

bool KriterijSortiranja(int x, int  y){
    int djeliocix=BrojDjelioca(x);
    int djeliociy=BrojDjelioca(y);
    if (djeliocix==djeliociy) return x<y;
    return djeliocix>djeliociy;
}


void SortirajPoBrojuDjelilaca(int *poc, int brojel){

        sort(poc, poc+brojel, KriterijSortiranja);
    
}
 

bool PretraziBinarno(int *poc, int brojel, int trazeni){
   
    binary_search( poc, poc+brojel ,trazeni);
}


int main ()
{
        cout<<"Unesite broj elemenata niza: "<<endl;
        int n;
        cin>>n;
        int* niz= new int[n];
        cout<<"Unesite elemente niza: "<<endl;
        

    try{

        for(int i=0; i<n; i++){
            cin>>niz[i];
        }
        
        SortirajPoBrojuDjelilaca(niz, n);
        cout<<"Sortiran niz glasi: ";
        for( int i=0; i<n; i++){
            cout<<niz[i]<<" ";
           
        }
        
        cout<<endl<<"Unesite element koji treba binarno pretraziti: "<<endl;
        int trazeni;
        cin>>trazeni;
        if(!PretraziBinarno(niz, n, trazeni)) cout<<"Trazeni element se ne nalazi u nizu."<<endl;
        else cout<<"Trazeni element se nalazi u nizu.";

    delete[] niz;
    }
    catch(bad_alloc){
        cout<<"Nedovoljno memorije";
    }
	return 0;
}