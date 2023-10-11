//TP 2018/2019: ZSR 6, Zadatak 17
#include <iostream>
#include <new>
#include <stdexcept>

using namespace std;

template<typename Tip>

Tip** AlocirajKontinualno( Tip** a, int m, int n){
    Tip** kontinualna=new Tip*[m];

    try{
        kontinualna[0]= new Tip[m*n]{0};
        for(int i=1; i<m; i++) kontinualna[i]=kontinualna[i-1]+n;
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                kontinualna[i][j]=a[i][j];
            }
        }
    }
    catch(bad_alloc){
        delete[] kontinualna[0];
        delete[] kontinualna;

    }
    return kontinualna;
}

int main ()
{
    
        int** matrica=new int*[5];
    try{
        for(int i=0; i<5; i++){
            matrica[i]=new int[3];
            for(int j=0; j<3; j++){
                matrica[i][j]=1;
            }
        }

        int** kontinualna;
        kontinualna=AlocirajKontinualno(matrica, 5,3);

        for(int i=0; i<5; i++){
            for(int j=0; j<3; j++){
                cout<<matrica[i][j];
            }
            cout<<endl;
        }
        
    }
    catch(bad_alloc){
        cout<<"Nema memorije";
        for(int i=0; i<5; i++) delete[] matrica[i];
        delete[] matrica;
    }
	return 0;
}