//TP 2018/2019: Ispit 1, Zadatak 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename TipEl>

TipEl SumaEl(vector<TipEl> v){
    TipEl suma=0;
    for(int i=0; i<v.size(); i++){
        suma+=v.at(i);
    }
    return suma;
}

template<typename TipElem>

bool Kriterij(vector<TipElem> v1, vector<TipElem> v2){
    if(SumaEl(v1)> SumaEl(v2)) return v1<v2;
    if(SumaEl(v1)==SumaEl(v2)){
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v2.site(); j++){
                if (v1.at(i)<v2.at(j)) return v1<v2;
            }
        }
    }
}

template<typename NekiTip>

void SortirajMatricu (vector<vector<NekiTip>> &matrica){

    std::sort(matrica.at(0), matrica.at(matrica.size()), Kriterij);
   
}

int main ()
{
    cout<<"Unesi dimenzije: "<<endl;
    int n;
    int m;
    cin>>n;
    cin>>m;
    cout<<"Unesi elemente: "<<endl;
    vector<vector<int>> matrica(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int el;
            cin>>el;
            matrica.at(i).at(j)=el;
        }
    }
    SortirajMatricu(matrica);

    cout<<"Matrica nakon sortiranja: "<<endl;

    for(int i=0; i<matrica.size(); i++){
        for(int j=0; j<matrica.at(i).size(); j++){
            cout<<matrica.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
	return 0;
}