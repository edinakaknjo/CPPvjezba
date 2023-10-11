//TP 2018/2019: ZSR 6, Zadatak 30
#include <iostream>
#include <new>

using namespace std;

void Alociraj(char** &mat1, char** mat2, int n){

    mat1=new char*[n];

    try{
        for(int i=0; i<n; i++){
            mat1[i]= new char[i+1]{'*'};
        }
    }
    catch(bad_alloc){
        for(int i=0; i<n; i++) delete[] mat1[i];
        delete[] mat1;
    }

    mat2=new char*[n];

    try{
        mat2[0]=new char[n*n]{'*'};
        for(int i=n; i>1; i--) mat2[i]=mat2[i-1]+n;
    }
    catch(bad_alloc){
        delete mat2[0];
        delete[] mat2;
    }
}

int main ()
{
    try{
    char** matrica1;
    char** matrica2;

    Alociraj(matrica1, matrica2, 5);

    for(int i=0; i<5; i++){
        for(int j=0; j<i+1; j++){
            cout<<matrica1[i][j];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5-i; j++){
            cout<<matrica2[i][j];
        }
    }
    }
    catch(bad_alloc){
        cout<<"Nema memorije";
    }
	return 0;
}