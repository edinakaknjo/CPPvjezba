//TP 2018/2019: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>


using namespace std;

int brojcif(int a){
    int cif;
    if (a==numeric_limits<int>::min()) {return cif=11;}

    else if (a<0 && a!=numeric_limits<int>::min()) {
        cif=1;
        a=(-1)*a;
    }
    else {
        cif=0;
        a=1*a;
    }
    do{
        a=a/10;
        cif++;
    }while(a>=1);
return cif;
}
typedef vector<vector<int>> Matrica;


int NajvecaSirina( vector<vector<int>>m){

    int naj=0;
    vector<int>sirine;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].size(); j++){
            /*for(int k=0; k<m.size(); k++){*/
               /* naj=brojcif(m[i][j]);
                sirine.at(k)=brojcif(m[i][j]);
                if(k==0) naj=sirine.at(0);
                else */
               
                if (brojcif(m[i][j])>naj) 
                        naj=brojcif(m[i][j]);
             }
        
    }  

return naj;
}

vector<vector<int>>KroneckerovProizvod(vector<int> a, vector<int>b){

    vector<vector<int>>mat(a.size(),vector<int> (b.size()));
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            mat[i][j]= a.at(i)*b.at(j);
        }
    }
    return mat;      
}

int main ()
{
    vector<int> a;
    cout<<"Unesite broj elemenata prvog vektora: ";
    int el1;
    cin>>el1;
    cout<<"Unesite elemente prvog vektora: ";
    for(int i=0; i<el1; i++){
        int br1;
        cin>>br1;
        a.push_back(br1);
    }
    cout<<"Unesite broj elemenata drugog vektora: ";
    int el2;
    cin>>el2;
    vector<int>b;
    cout<<"Unesite elemente drugog vektora: ";
    for(int j=0; j<el2; j++){
        int br2;
        cin>>br2;
        b.push_back(br2);
    }

    cout<<endl;

    vector<vector<int>>KronekerovaMat = KroneckerovProizvod(a, b);

    for(int e=0; e<el1; e++){
        for(int f=0; f<el2; f++){
            cout<<setw(NajvecaSirina(KronekerovaMat)+1)<< KronekerovaMat[e][f];
            
        }
        cout<<endl;}


	return 0;
}