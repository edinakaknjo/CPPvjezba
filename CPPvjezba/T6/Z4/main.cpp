#include <iostream>
#include <new>

using namespace std;

int** KreirajTrougao(int n){
    if(n<=0){
        throw domain_error("Broj redova mora biti pozitivan");
    }
    int** trougao=new int*[n];
    try{    
        trougao[0] = new int[n*n];
        for(int i=1; i<n; i++) trougao[i]=trougao[i-1]+2*i-1;
        for(int i=0; i<n; i++){
            int el=i+1;
            bool dopola=false;
            for(int j=0; j<2*i+1; j++){
                if(el==1) dopola=true;
                if(!dopola) trougao[i][j]=el--;
                else trougao[i][j]=el++;
            }
        }
    }
    catch(bad_alloc){
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
        delete[] trougao[0];
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