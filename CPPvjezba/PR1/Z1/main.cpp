//TP 2018/2019: Ispit 1, Zadatak 1
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int DigitalniKorjen(int n) {
  int sumacif = 0;
  while (n != 0) {
      int cif;
    cif = abs(n % 10);
    sumacif += cif;
    n /= 10;
  }

  if (sumacif < 10)
    return sumacif;

  else {
      int novasuma=0;
     while ( sumacif >= 10) { 
         while(sumacif!=0){
      int cifrasume;
      cifrasume = sumacif % 10;
      sumacif /= 10;
      novasuma+=cifrasume;}
      }

      sumacif=novasuma;
    }

    return sumacif;
  
}

array<vector<int>,10> Razvrstaj(vector<int> brojevi){
    array<vector<int>,10> vracena;
    for(int i=0; i<brojevi.size(); i++){
        int indeks=DigitalniKorjen(brojevi.at(i));
        vector<int> naovomindeksu;
        vracena.at(indeks).push_back(brojevi.at(i));
    }
    return vracena;
} 

int main(){

    cout<<"Koliko ima brojeva: "<<endl;
    int n;
    cin>>n;
    cout<<"Unesi brojeve: "<<endl;
    vector<int> brojevi;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        brojevi.push_back(el);
    }
    array<vector<int>,10> vracena=Razvrstaj(brojevi);
    for(int i=0; i<10; i++){
        cout<<"Digitalni korjen "<<i<<": ";
        vector<int> saovimdig;
        saovimdig=vracena.at(i);
        for(int i=0; i<saovimdig.size(); i++){
            cout<<saovimdig.at(i)<<" ";
        }
        cout<<endl;
    }

    return 0;
}