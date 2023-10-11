#include <algorithm>
#include <cstring>
#include <iostream>


using namespace std;

int main() {

  cout << "Koliko zelite recenica: ";
  int n;
  cin >> n;
  cin.ignore(10000, '\n');
  cout << "Unesite recenice: " << endl;
  try {
    char **pok = new char *[n] {};
    try {
      for (int i = 0; i < n; i++) {
        char niz[1000];
        cin.getline(niz, 1000);
        pok[i] = new char[strlen(niz) + 1];
        strcpy(pok[i], niz);
      }

      sort(pok, pok + n,
           [](char *pok1, char *pok2) { return strcmp(pok1, pok2) < 0; });

      cout << "Sortirane recenice:" << endl;
      for (int i = 0; i < n; i++) {
        cout << pok[i] << endl;
      }
      for (int i = 0; i < n; i++)
        delete[] pok[i];
      delete[] pok;

    } catch (bad_alloc) {
      for (int i = 0; i < n; i++)
        delete[] pok[i];
      delete[] pok;
      throw;
    }

  } catch (bad_alloc) {
    cout << "Problemi s memorijom!" << endl;
  }
}