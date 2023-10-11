//TP 2018/2019: ZSR 6, Zadatak 19
#include <iostream>
#include <new>
#include <array>

using namespace std;

template<typename Tip>

Tip** Grbavamat( int* niz, int brojel){
    for(int i=0; i<brojel; i++){
        if(niz[i]<0 ) throw domain_error("Ne moze biti neg br el");
    }

    Tip** matrica=new Tip*[brojel]{};
    try{
        for(int i=0; i<brojel; i++){
            matrica[i]= new Tip[niz[i]]{};
            
        }
    }
    catch(bad_alloc){
        for(int i=0; i<brojel; i++) delete[] matrica[i];
        delete[] matrica;
    }

    return matrica;
}
int main ()
{

    try{
        int niz[5]= {4, 6, 2, 7, 5};
        int** mat(Grbavamat<int>(niz, 5));
        for(int i=0; i<5; i++) {
            for(int j=0; j<niz[i]; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

        for(int i=0; i<5; i++) delete[] mat[i];
        delete[] mat;
    }
    catch(bad_alloc){cout<<"Nema memorije";}
	return 0;
}