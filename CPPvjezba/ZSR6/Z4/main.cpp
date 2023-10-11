//TP 2018/2019: ZSR 6, Zadatak 4
#include <iostream>
#include <new>

using namespace std;

bool JeLiProst(int n){
    for(int i=2; i<=n/2; i++){
        if(n%i==0) return false;
    }
    return true;
}

int* DinamickiAlociraj (int n){
    int* niz;
    niz=new int[n];
    try{
        int brojacprostih=0;
        int brojpreskocenih=2;
        for(int i=2; i<(i*i); i++){
            if(JeLiProst(i)) {
                niz[i-brojpreskocenih]=i;
                 brojacprostih++;}
                 else brojpreskocenih++;
            
            if(brojacprostih==n) break;
        }
    }
    catch(bad_alloc){
        delete[] niz;
    }
    return niz;
}

int main ()
{
    try{
        int* niz;
        niz=DinamickiAlociraj(10);
        for(int i=0; i<10; i++){
            cout<<niz[i]<<" ";
        }
        delete niz ;
    }
    catch(bad_alloc){
        cout<<"Nema memorije";
    }
	return 0;
}