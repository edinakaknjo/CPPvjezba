//TP 2018/2019: ZSR 5, Zadatak 17
#include <iostream>
#include <vector>

using namespace std;

template <class It, class Pok>

It Podblok(It poc1, It kraj1, Pok poc2, Pok kraj2) {
  It index;
  int brojel2 = kraj2 - poc2;
  bool jestpodblok;

  while (poc1 != kraj1) { //// 334567   12567
    if (*poc1 == *poc2) {
      index = poc1;
      It pomocniza1 = poc1;
      Pok pomocniza2 = poc2;
      jestpodblok = true;
      while (pomocniza1 != kraj1 && jestpodblok == true && pomocniza2!=kraj2) {
        if (*pomocniza1 != *pomocniza2)
          jestpodblok = false;
        pomocniza1++;
        pomocniza2++;
      }
    }
    poc1++;
  }

  if (jestpodblok)
    return index;
  else
    return kraj1;
}

int main() {
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> v2{5, 6, 7};
  auto it= Podblok(v1.begin(), v1.end(), v2.begin(), v2.end());
  while(it!=v1.end()) cout<<*it++<<" ";
  return 0;
}