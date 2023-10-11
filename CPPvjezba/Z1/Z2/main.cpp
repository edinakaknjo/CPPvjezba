#include <iostream>
#include <vector>
#include <array>
 
using namespace std;
 
 
int JesuLiSveNule(vector<vector<double>>matrica){
    int brojnula=(-1);
    for(int i=0; i<matrica.size(); i++){
        for (int j=0; j<matrica.at(i).size(); j++){
            if (matrica.at(i).at(j)!=(0)){
                brojnula++;
            }
        }
    }
    return brojnula;
}
 
 
array<int,4> RasponMatrice(vector<vector<double>>matrica){
 
   for(int i=0; i<matrica.size(); i++){
            if (matrica.at(0).size()!=matrica.at(i).size()){
                throw domain_error("Nekorektna matrica");
            }
    }
 
    if( matrica.size()==0){
        throw domain_error("Raspon nije definiran za nul-matricu ili praznu matricu");
    }
 
    if(JesuLiSveNule(matrica)==(-1)){
        throw domain_error("Raspon nije definiran za nul-matricu ili praznu matricu");
    }
 
    array<int,4> niz;
    int imin=0, jmin=0, imax=0, jmax=0;
 
    vector<int> v1;
    vector<int> v2;
 
    for(int i=0; i<matrica.size(); i++){
        for(int j=0; j<matrica.size(); j++){
            if(matrica.at(i).at(j)!=(0)){
                v1.push_back(i+1);
                v2.push_back(j+1);
            }
        }
    }
 
    int minel1=v1.at(0);
    for(int i=1; i<v1.size(); i++){
        if (v1.at(i)<minel1) minel1=v1.at(i);
    }
 
    imin=minel1;
 
    int maxel1=v1.at(0);
    for(int i=1; i<v1.size(); i++){
        if (v1.at(i)>maxel1) maxel1=v1.at(i);
    }
 
    imax=maxel1;
 
    int minel2=v2.at(0);
    for(int j=1; j<v1.size(); j++){
        if (v2.at(j)<minel2) minel2=v2.at(j);
    }
 
    jmin=minel2;
 
    int maxel2=v2.at(0);
    for(int j=1; j<v2.size(); j++){
        if (v2.at(j)>maxel2) maxel2=v2.at(j);
    }
 
    jmax=maxel2;
 
    niz={imin, jmin, imax, jmax};
 
    return niz;
 
}
 
 
vector<vector<double>> Matrica (int red, int kol) {
    vector<vector<double>> matrica=vector<vector<double>> (red, vector <double> (kol));
    return matrica;
}
 
 
int main(){
 
     try{
    cout<<"Unesite dimenziju matrice u formatu m x n: ";
    int m;
    cin>>m;
    char x;
    cin>>x;
    int n;
    cin>>n;
 
    vector<vector<double>> mat=Matrica(m,n);
 
    cout<<"Unesite elemente matrice:"<<endl;
     for(int i=0;i<m; i++){
        cout<<"Elementi "<<i+1<<". reda: ";
        for(int j=0; j<n; j++){
            cin>>mat.at(i).at(j);
        }
    }
 
    cin.clear();
    cin.ignore(1000,'\n');
 
 
 
        array<int,4> rasponove=RasponMatrice(mat);
 
        cout<<endl<<"Raspon matrice je od ("<<rasponove.at(0)<<","<<rasponove.at(1)<<") do ("<<
        rasponove.at(2)<<","<<rasponove.at(3)<<").";
    }
 
 
    catch(std::domain_error e) {cout<<"IZUZETAK: "<<e.what()<<"!";}
 
    return 0;
 
}