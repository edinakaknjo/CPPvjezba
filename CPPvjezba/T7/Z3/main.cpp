#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>


using namespace std;

int main() {

  cout << "Koliko zelite recenica: ";
  int n;
  cin >> n;
  cin.ignore(10000, '\n');
  cout << "Unesite recenice: " << endl;
  try {
    string** pok= new string *[n]{};
    try {
      for (int i = 0; i < n; i++) {
        pok[i] = new string;
        getline(cin, *pok[i]);
      }

      sort(pok, pok + n,
           [](string *pok1, string *pok2) { return *pok1<*pok2; });

      cout << "Sortirane recenice:" << endl;
      for (int i = 0; i < n; i++) {
        cout << *pok[i] << endl;
      }
      for (int i = 0; i < n; i++)
        delete  pok[i];
      delete[] pok;

    } catch (bad_alloc) {
      for (int i = 0; i < n; i++)
        delete pok[i];
      delete[] pok;
      throw;
    }

  } catch (bad_alloc) {
    cout << "Problemi s memorijom!" << endl;
  }
}