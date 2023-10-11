// TP 2018/2019: ZSR 6, Zadatak 13
#include <iostream>
#include <new>

using namespace std;

template <class Tip, class Tipbr>

void Funkcija(Tip** &a, int m, int n, Tipbr v, bool mod) {

  a = new Tip *[n];
  try {
    if (!mod) {
      for (int i = 0; i < n; i++) {
        a[i] = new Tip[m]{v};
      }
    }
    if (mod) {
      a[0] = new int(n * m);
      for (int i = 1; i < n; i++)
        a[i] = a[i - 1] + m;
    }
  } catch (bad_alloc) {
    if(!mod){
        for (int i = 0; i < n; i++)
      delete[] a[i];
    delete[] a;}

    else delete[] a;

    throw;
  }
}

bool Funk(int x){
    x=2;
    return (x==2);
}

int main() {
  try {
    int a, b;
    a = 3;
    b = 3;

    int **matrica;

    Funkcija(matrica, a, b, 0, false);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrica[i][j];
      }
    }
  } catch (bad_alloc) {
    cout << "Nema mem";
  }

  return 0;
}