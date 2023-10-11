// TP 2018/2019: ZSR 4, Zadatak 49
#include <iostream>
#include <type_traits>
#include <vector>


using namespace std;

template <typename UporediviTip>

void UkloniNadprosjecne(vector<UporediviTip> &v) {
  UporediviTip suma = 0;
  for (int i = 0; i < v.size(); i++) {
    suma += v.at(i);
  }
  UporediviTip prosjek = suma / 2;

  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) > prosjek) {
      int indexIzbacivanja = i;
      for (int j = indexIzbacivanja; j + 1 < v.size(); j++) {
        v.at(j) = v.at(j + 1);
      }
      v.resize(v.size() - 1);
    }
  }
}

int main() {
  vector<int> v{1, 2, 3, 45, 3, 6, 7, 2, 3, 7, 86, 23, 12};
  UkloniNadprosjecne<int>(v);
  int i = 0;
  while (i != v.size()) {
    cout << v.at(i) << " ";
    i++;
  }
  return 0;
}