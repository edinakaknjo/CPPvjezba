// TP 2018/2019: Tutorijal 3, Zadatak 7
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::setw;
using std::domain_error;
using std::numeric_limits;


vector<vector<int>> PascalovTrougao(int n) {
    if(n<0)
    throw domain_error("Broj redova ne smije biti negativan");
  vector<vector<int>> m(n);
  for(int i=0; i<n; i++){
      m[i].resize(i+1);
}
    for(int i=0; i<n; i++){
        
        for(int j=0; j<m[i].size();j++){
            if(i==j) m[i][j]=1;
            else if (j==0) m[i][j]=1;
            else m[i][j]=m[i-1][j-1]+m[i-1][j];
        }
    }
  return m;
}

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
            
                if (brojcif(m[i][j])>naj) 
                        naj=brojcif(m[i][j]);
             }
        
    }  

return naj;
}

int main() {
  cout << "Unesite broj redova: " << endl;
  int n;
  cin >> n;
  vector<vector<int>> matrica;
  matrica=PascalovTrougao(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < matrica[i].size(); j++) {
      cout << setw(NajvecaSirina(matrica)+1)<<matrica[i][j];}
    cout << endl;
  }

  return 0;
}