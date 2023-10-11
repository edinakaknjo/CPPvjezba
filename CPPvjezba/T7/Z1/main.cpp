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
    char **pok = new char *[n]{};
    try {
      for (int i = 0; i < n; i++) {
        char niz[1000];
        cin.getline(niz, 1000);
        pok[i] = new char[strlen(niz) + 1];
        strcpy(pok[i], niz);
      }

      for (int i = 0; i + 1 < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
          if (strcmp(pok[j], pok[min]) < 0)
            min = j;
        }
        if (i != min)
          swap(pok[i], pok[min]);
      }

      cout << "Sortirane recenice:" << endl;
      for (int i = 0; i < n; i++) {
        cout << pok[i] << endl;
      }
      for(int i=0; i<n; i++) delete[] pok[i];
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