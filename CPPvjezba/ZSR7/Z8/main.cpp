// TP 2018/2019: ZSR 7, Zadatak 8
#include <complex>
#include <iostream>
#include <list>
#include <new>


using namespace std;

struct Kompleksni {
  double re, im;
  Kompleksni *sljedeci;
};

Kompleksni *KreirajListu(list<complex<double>> brojevi) {
  Kompleksni *pocetak{}, *prethodni;
  for (auto it = brojevi.begin(); it != brojevi.end(); it++) {
    Kompleksni *novi(new Kompleksni);

    novi->re = it->real();
    novi->im = it->imag();
    novi->sljedeci = nullptr;
    if (!pocetak)
      pocetak = novi;
    else
      prethodni->sljedeci = novi;
    prethodni = novi;
  }
  return pocetak;
}

void ObrisiListu(Kompleksni *pocetak){
    Kompleksni*sljedeci=nullptr;
    for()
}

int main() {
  list<complex<double>> lista{{1, 2}, {2, 2}, {3, 3}};
  auto pok = KreirajListu(lista);
  for (Kompleksni *p = pok; p != nullptr; p=p->sljedeci) {
    cout << p->re << " " << p->im << endl;
  }

  return 0;
}