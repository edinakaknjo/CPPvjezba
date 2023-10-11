#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

typedef shared_ptr<string> dijeljeniPok;
typedef shared_ptr<dijeljeniPok> nizDijeljenih;

int main() {

  cout << "Koliko zelite recenica: ";
  int n;
  cin >> n;
  cin.ignore(10000, '\n');
  cout << "Unesite recenice: " << endl;
  try {
    nizDijeljenih pok(new dijeljeniPok[n], [](dijeljeniPok* p){ delete[] p;});

    for (int i = 0; i < n; i++) {
      pok.get()[i] = make_shared<string>();
      getline (cin, *(pok.get()[i]));
    }

    sort(pok.get(), pok.get() + n,
         [](dijeljeniPok pok1, dijeljeniPok pok2) { return *pok1 < *pok2; });

    cout << "Sortirane recenice:" << endl;
    for (int i = 0; i < n; i++) {
      cout << *(pok.get()[i]) << endl;
    }

  } catch (bad_alloc) {
    cout << "Problemi s memorijom!" << endl;
  }
}