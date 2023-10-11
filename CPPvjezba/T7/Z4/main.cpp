#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

typedef shared_ptr<string> dijeljeniPok;
typedef unique_ptr<dijeljeniPok[]> jednostruki;

int main() {

  cout << "Koliko zelite recenica: ";
  int n;
  cin >> n;
  cin.ignore(10000, '\n');
  cout << "Unesite recenice: " << endl;
  try {
    jednostruki pok(new dijeljeniPok[n]);

    for (int i = 0; i < n; i++) {
      pok[i] = make_shared<string>();
      getline(cin, *pok[i]);
    }

    sort(pok.get(), pok.get() + n,
         [](dijeljeniPok pok1, dijeljeniPok pok2) { return *pok1 < *pok2; });

    cout << "Sortirane recenice:" << endl;
    for (int i = 0; i < n; i++) {
      cout << *pok[i] << endl;
    }

  } catch (bad_alloc) {
    cout << "Problemi s memorijom!" << endl;
  }
}