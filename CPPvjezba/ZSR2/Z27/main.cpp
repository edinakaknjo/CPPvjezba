// TP 2018/2019: ZSR 2, Zadatak 27
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool ProizPrirodnih(int br) {
  int suma = 0;
  for (int i = 1; i < br; i++) {
    suma = i * (i + 1) * (i + 2) * (i + 3) * (i + 4);
    if (suma > br) {
      return false;
      break;
    }
    if (suma == br) {
      return true;
      break;
    }
  }
  return true;
}

vector<bool> LogVr(vector<int> brojevi) {
  vector<bool> v;
  for (int i = 0; i < brojevi.size(); i++) {
    v.push_back(ProizPrirodnih(brojevi.at(i)));
  }
  return v;
}

int main(){
    vector<int>v {45, 720,110};
    vector<bool> v2=LogVr(v);
    int i=0;
    while(i!=v2.size()){
        cout<<v2.at(i)<<" ";
        i++;
    }
     return 0; }