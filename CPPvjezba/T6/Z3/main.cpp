#include <iostream>
#include <new>
 
using namespace std;
 
int** KreirajTrougao(int n){
    if(n<=0){
        throw domain_error("Broj redova mora biti pozitivan");
    }
    int**trougao=new int*[n]{nullptr};
    
    try{
        for(int i=0; i<n; i++){
            trougao[i]= new int[2*i+1];
            for(int j=0; j<2*i+1; j++){
                if (j<=i) trougao[i][j]=i+1-j;
                else trougao[i][j]=1+j-i;
            }
        }
    }
    catch(bad_alloc){
        for(int i=0; i<n; i++) delete[] trougao[i];
        delete[] trougao;
        throw;
    }
    return trougao;
}
 
int main ()
{
    try{
        cout<<"Koliko zelite redova: ";
        int n=0;
        cin>>n;
        int** trougao(KreirajTrougao(n));
        for(int i=0; i<n; i++){
            for (int j=0; j<i*2+1; j++){
                cout<<trougao[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0; i<n; i++) delete[] trougao[i];
        delete[] trougao;
        
    }
    catch(bad_alloc){
        cout<<"Izuzetak: Nedovoljno memorije!"<<endl;
    }
    catch(domain_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;
    }
    return 0;
}
