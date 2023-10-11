//TP 2018/2019: Zadaća 1, Zadatak 3
#include <iostream>
#include <deque>
#include <iomanip>
#include <limits>

using namespace std;

deque<deque<double>> EkspanzijaMatrice(deque<deque<double>> mat, int p, int q){

    if(p<=0 || q<=0) throw domain_error("Nelegalni parametri");

    int brojel=0;

    for(int i=0; i<mat.size(); i++){
        for (int j=0; j<mat.at(i).size(); j++){
            brojel++;
        }
    }

    if(brojel==0) throw domain_error("Nekorektna matrica");

    for(int i=0; i<mat.size(); i++)
        if((mat.at(i).size()!= mat.at(0).size())) throw domain_error("Nekorektna matrica");

    if(mat.size()==0 || mat.at(0).size()==0) return mat;

    int m=mat.size();
    int n=mat.at(0).size();

    deque<deque<double>> novamatrica(p*m, deque<double>(q*n));

    for(int i=0;i<m; i++){
        for(int j=0;j<n;j++){
        for(int k=i*p; k<p*m; k++){
        for(int l=j*q;l<q*n; l++){
        
        novamatrica.at(k).at(l)=mat.at(i).at(j);}
        }
        }
    }
return novamatrica;
}


int main ()
{
try
   { cout<<"Unesite broj redova matrice A (m): ";
    int m;
    cin>>m;
    cout<<"Unesite broj kolona matrice A (n): ";
    int n;
    cin>>n;

    deque<deque<double>> nasamat(m,deque<double>(n));

    for(int i=0; i<m; i++){
        cout<<"Unesite "<<i+1<<". red matrice: ";
        for(int j=0;j<n; j++){
            cin>>nasamat.at(i).at(j);
        }
    }

    cout<<"Unesite dimenziju ekspanzije p: ";
    int p;
    cin>>p;
    cout<<"Unesite dimenziju ekspanzije q: ";
    int q;
    cin>>q;

    cout<<"Ekspanzija matrice A glasi: "<<endl;

    deque<deque<double>>novamat= EkspanzijaMatrice(nasamat, p, q);

    for(int i=0; i<m*p; i++){
        for (int j=0; j<n*q; j++){
            cout<<setw(11)<<setprecision(2)<<fixed<<novamat.at(i).at(j);
        }
        cout<<endl;
    }
   }
catch(domain_error err){
    std::cout << err.what();
   }


	return 0;
}