//TP 2018/2019: Ispit 1, Zadatak 2
#include <iostream>
#include <vector>

using namespace std;

bool JeLiNul(vector<double>v){
    for(int i=0; i<v.size(); i++){
        if(v.at(i)!=0) return false;
    }
    return true;
}

void AnalizaMatrice(vector<vector<double>> mat, vector<int> &nulred, vector<int> &nulkol){
    for(int i=0; i+1<mat.size(); i++){
        if(mat.at(i).size()!= mat.at(i+1).size()) throw domain_error("Grbava matrica");
    }

    for(int i=0; i<mat.size(); i++){
        vector<double> ovakol;
        for(int j=0; j<mat.size(); j++){
            ovakol.push_back(mat.at(i).at(j));
        }
        int indeks;
        if(JeLiNul(ovakol)) indeks=i;
        nulkol.push_back(i);
    }

    for(int i=0; i<mat.size(); i++){
        vector<double> ovajred;
        for(int j=0; j<mat.size(); j++){
            ovajred.push_back(mat.at(j).at(i));
        }
        int indeks;
        if(JeLiNul(ovajred)) indeks=i;
        nulred.push_back(indeks);
    }
}
int main ()
{
    try{
    cout<<"Unesi dimenzije: "<<endl;
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<double>> matrica(n, vector<double>(m));
    cout<<"Unesi elemente: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            double el;
            cin>>el;
            matrica.at(i).at(j)=el;
        }
    }
    vector<int> nulred;
    vector<int> nulkol;

    AnalizaMatrice(matrica, nulred, nulkol);

    cout<<endl<<"Nul-redovi: ";
    for(int i=0; i<nulred.size(); i++){
        cout<<nulred.at(i)<<" ";
    }

    cout<<endl<<"Nul-kolone: ";
    for (int i=0; i<nulkol.size(); i++){
        cout<<nulkol.at(i)<<" ";
    }
    }
    catch(domain_error e){
        cout<<e.what();
    }
	return 0;
}