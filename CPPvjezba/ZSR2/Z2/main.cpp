//TP 2018/2019: ZSR 2, Zadatak 2

#include <iostream>
#include <vector>

using namespace std;



bool Ima(int n) {
  vector<int> cifre(10, 0);
  while (n != 0) {
    int cifra = n % 10;
    cifre.at(cifra)++;
    n /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (cifre.at(i) >1)
      return true;
  }

  return false;
}

int main() {
  cout << Ima(4321);
  return 0;
}