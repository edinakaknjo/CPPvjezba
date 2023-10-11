#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>


using namespace std;

template <typename Tip> Tip *GenerirajStepeneDvojke(int n) {
  if (n <= 0) {
    throw domain_error("Broj elemenata mora biti pozitivan");
  }
  try {
    Tip *niz = new Tip[n];
    Tip el = 1;

    for (int i = 0; i < n; i++) {
      niz[i] = el;
      if (i != (n - 1) && (numeric_limits<Tip>::max()) / 2 < el) {
        delete[] niz;
        throw overflow_error("Prekoracen dozvoljeni opseg");
      }
      el *= 2;
    }
    return niz;
  } catch (bad_alloc) {
    throw runtime_error("Alokacija nije uspjela");
  }
}
int main() {
  try {
    cout << "Koliko zelite elemenata: ";
    int n = 0;
    cin >> n;
    int *br = GenerirajStepeneDvojke<int>(n);
    for (int i = 0; i < n; i++) {
      cout << fixed << setprecision(0) << br[i] << " ";
    }
    delete[] br;
  }

  catch (domain_error e) {
    cout << "Izuzetak: " << e.what() << endl;
  } catch (overflow_error e) {
    cout << "Izuzetak: " << e.what() << endl;
  } catch (runtime_error e) {
    cout << "Izuzetak: " << e.what() << endl;
  }
  return 0;
}