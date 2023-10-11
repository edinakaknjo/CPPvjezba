// TP 2018/2019: ZSR 7, Zadatak 24
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

template <typename TipElementa>

class Skup {
  vector<TipElementa> v;
  void PronadjiIUbaci(TipElementa el) {
    auto pozicija = lower_bound(v.begin(), v.end(), el);
    if (pozicija == v.end() || *pozicija != el)
      v.insert(pozicija, el);
  }

public:
  Skup(initializer_list<TipElementa> s) {
    for (auto el : s) {
      PronadjiIUbaci(el);
    }
  }
  Skup() {}

  int Velicina(vector<TipElementa> s) const { return s.size(); }
  void Dodaj(TipElementa broj) { PronadjiIUbaci(broj); }
  void Izbrisi(TipElementa broj) {

    auto pozicija = lower_bound(v.begin(), v.end(), broj);
    if (!(pozicija == v.end() || *pozicija != broj))
      v.erase(pozicija);
  }

  bool ImaLiGa(TipElementa elem) {
    return binary_search(v.begin(), v.end(), elem);
  }

  void Ispisi() const {

    for (auto it = v.begin(); it != v.end(); it++) {
      cout << *it << " ";
    }
    cout<<endl;
  }
};
int main() {
  Skup<int> s1;
  Skup<int> s2{2,  2,  2, 2,  2,  2,   2,   -1,  -1,
               -1, 66, 6, 66, 66, 125, 125, -99, -99};
  s1.Ispisi();

  s2.Ispisi();
  s2.Dodaj(-55);
  s2.Ispisi();
  s2.Izbrisi(2);
  s2.Ispisi();

  s2.Izbrisi(125);
  s2.Ispisi();

  cout << boolalpha << s2.ImaLiGa(125) << " " << s2.ImaLiGa(-55) << endl;
  cout << endl;
  return 0;
}