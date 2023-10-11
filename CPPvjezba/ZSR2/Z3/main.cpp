// TP 2018/2019: ZSR 2, Zadatak 3
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

bool Ima(int n) {
  vector<int> cifre;
  int brojac = 0;
  while (n != 0) {
    int cifra = abs(n % 10);
    cifre.push_back(cifra);
    n /= 10;
    brojac++;
  }

  for (int i=brojac-1; i>0; i--){
      if( i!=1 && cifre.at(i)==cifre.at(i-1)) return true;
  }

  return false;
}

int main() { 
    cout<<Ima(-12223);
    return 0; }