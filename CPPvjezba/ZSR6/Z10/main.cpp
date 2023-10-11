//TP 2018/2019: ZSR 6, Zadatak 10
#include <iostream>
#include <new>

using namespace std;

template<typename NekiTip>

void KreirajMatricu( int m, int n, NekiTip** &matrica){
    matrica=new NekiTip*[m]{};

    try
    {
        for(int i=0; i<m; i++){
            matrica[i]=new NekiTip[n];
        }
    }
    catch(bad_alloc){
        for(int i=0; i<m; i++) delete[] matrica[i];
        delete[] matrica;
        throw;
    }
}

int main ()
{
    try{
        int** matrica;
        KreirajMatricu(3, 5, matrica);

        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                cout<<matrica[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    catch(bad_alloc){
        cout<<"nema prostora";
        
    }
	return 0;
}