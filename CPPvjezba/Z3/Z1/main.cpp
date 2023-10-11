// TP 2018/2019: Zadaća 3, Zadatak 1
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

constexpr double EPSILON = 1e-15;

vector<pair<double, double>> BinarnoZaPar(vector<pair<double, double>> parovi,
                                          double x) {
  pair<double, double> par = make_pair(x, 0);
  auto it = upper_bound(parovi.begin(), parovi.end(), par);

  double x1 = (it - 1)->first, x2 = it->first, y2 = it->second,
         y1 = (it - 1)->second;

  vector<pair<double, double>> prviisljedeci;
  pair<double, double> prvi = make_pair(x1, y1);
  pair<double, double> sljedeci = make_pair(x2, y2);

  prviisljedeci.push_back(prvi);
  prviisljedeci.push_back(sljedeci);

  return prviisljedeci;
}

void SortirajCvorove(vector<pair<double, double>> &cvorovi) {
  sort(cvorovi.begin(), cvorovi.end());
}

function<double(double)>
LinearnaInterpolacija(vector<pair<double, double>> cvorovi) {
  for (int i = 0; i < cvorovi.size(); i++) {
    double x1 = cvorovi.at(i).first;
    for (int j = 1; j < cvorovi.size(); j++) {
      double x2 = cvorovi.at(j).first;
      if (abs(x1 - x2) < EPSILON && i != j)
        throw domain_error("Neispravni cvorovi.");
    }
  }

  SortirajCvorove(cvorovi);

  return [cvorovi](double x) {
    if (x < cvorovi.at(0).first || x > cvorovi.at(cvorovi.size() - 1).first)
      throw range_error("Argument van opsega.");

    vector<pair<double, double>> v = BinarnoZaPar(cvorovi, x);
    pair<double, double> trazenipar = v.at(0);
    pair<double, double> sljpar = v.at(1);

    double rezultat = 0;
    rezultat = trazenipar.second + (((sljpar.second - trazenipar.second) /
                                     (sljpar.first - trazenipar.first)) *
                                    (x - trazenipar.first));
    return rezultat;
  };
}

function<double(double)> LinearnaAproksimacija(function<double(double)> f,
                                               double xmin, double xmax,
                                               double deltax) {
  if (deltax <= 0 || xmin > xmax)
    throw domain_error("Nekorektni parametri.");
  vector<double> cvorovi;

  for (double i = xmin; i <= xmax; i += deltax) {
    cvorovi.push_back(i);
  };

  vector<pair<double, double>> parovi;
  for (int i = 0; i < cvorovi.size(); i++) {
    double y;
    y = f(cvorovi.at(i));
    pair<double, double> par;
    par.first = cvorovi.at(i);
    par.second = y;
    parovi.push_back(par);
  }

  return [parovi](double x) {


    /*
    if (x < parovi.at(0).first || x > parovi.at(parovi.size() - 1).first){
      throw range_error("Argument izvan opsega.");}*/
    vector<pair<double, double>> v = BinarnoZaPar(parovi, x);
    pair<double, double> trazenipar = v.at(0);
    pair<double, double> sljpar = v.at(1);

    double rezultat = 0;
    rezultat = trazenipar.second + (((sljpar.second - trazenipar.second) /
                                     (sljpar.first - trazenipar.first)) *
                                    (x - trazenipar.first));
    return rezultat;
  };
}

double TestnaFunkcija(double x) {
  double rez = 0;
  rez = pow(x, 2) + sin(x);
  return rez;
}

int main() {

  cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " << endl;
  int opc;
  cin >> opc;

  if (opc == 1) {

    try {
      cout << "Unesite broj cvorova: " << endl;
      int brojcvorova;
      cin >> brojcvorova;
      cout << "Unesite cvorove kao parove x i y: " << endl;
      vector<pair<double, double>> cvorovi;
      for (int i = 0; i < brojcvorova; i++) {
        double prvi;
        double drugi;
        cin >> prvi;
        cin >> drugi;
        pair<double, double> cvor;
        cvor = make_pair(prvi, drugi);
        cvorovi.push_back(cvor);
      }

      for (;;) {

        auto f = LinearnaInterpolacija(cvorovi);

        cin.clear();
        cin.ignore(10000, '\n');
        double x;
        cout << "Unesite argument (ili \"kraj\" za kraj): " << endl;
        if (cin.peek() < '0' || cin.peek() > '9')
          break;
        else {
          cin >> x;
          cout << "f(" << x << ") = " << f(x) << endl;
        }
      }

    } catch (domain_error e) {
      cout << e.what();
    } catch (range_error f) {
      cout << f.what();
    }
  }

  if (opc == 2) {
    try {
      cout << "Unesite krajeve intervala i korak: " << endl;
      double xmin, xmax, deltax;
      cin >> xmin;
      cin >> xmax;
      cin >> deltax;

      auto f = LinearnaAproksimacija(TestnaFunkcija, xmin, xmax, deltax);

      for (;;) {

        cin.clear();
        cin.ignore(10000, '\n');
        double x;
        cout << "Unesite argument (ili \"kraj\" za kraj): " << endl;
        if (cin.peek() < '0' || cin.peek() > '9')
          break;
        else {
          cin >> x;
          cout << "f(" << x << ") = " << TestnaFunkcija(x) << " f_approx(" << x
               << ") = " << f(x) << endl;
        }
      }

    } catch (domain_error g) {
      cout << g.what();
    }
    
    
  }

  return 0;
}