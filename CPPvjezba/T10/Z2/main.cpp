/*
    TP 16/17 (Tutorijal 10, Zadatak 2)
        Autotestove pisala Nina Slamnik. Za sva pitanja,
        sugestije i primjedbe poslati mail na:
        nslamnik1@etf.unsa.ba

        Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <cmath>
#include <iomanip>
#include <iostream>


constexpr double epsilon = 1e-15;

using namespace std;

class Krug {
  double r;
  double pi = 4 * atan(1);

public:
  explicit Krug(double r) { Postavi(r); }

  void Postavi(double r) {
    if (r < epsilon)
      throw domain_error("Neispravan poluprecnik");
    this->r = r;
  }

  double DajPoluprecnik() const { return r; }
  double DajObim() const { return (2 * r * pi); }

  double DajPovrsinu() const { return (r * r * pi); }

  void Skaliraj(double faktorskaliranja) {

    if (faktorskaliranja < epsilon)
      throw domain_error("Neispravan faktor skaliranja");
    r = r * faktorskaliranja;
  }

  void Ispisi() const {
    std::cout << fixed<<setprecision(5)<< "R=" << DajPoluprecnik() 
              << " O=" << DajObim() << " P=" << DajPovrsinu();
  }
};

class Valjak {
  Krug baza;
  double visina;

public:
  explicit Valjak(double r, double visina) : baza(r) { Postavi(r, visina); }

  void Postavi(double r, double visina) {
    baza.Postavi(r);
    if (visina < epsilon)
      throw domain_error("Neispravna visina");

    this->visina = visina;
  }

  Krug DajBazu() const { return this->baza; }

  double DajPoluprecnikBaze() const { return this->baza.DajPoluprecnik(); }

  double DajVisinu() const { return visina; }

  double DajPovrsinu() const {
    return (this->baza.DajPovrsinu() * 2 + this->baza.DajObim() * visina);
  }

  double DajZapreminu() const { return (this->baza.DajPovrsinu() * visina); }

  void Skaliraj(double faktorskaliranja) {
    baza.Skaliraj(faktorskaliranja);
    visina = faktorskaliranja * visina;
  }

  void Ispisi() const {
    std::cout << fixed<<setprecision(5)<<"R=" << DajPoluprecnikBaze() << std::setprecision(5)
              << " H=" << DajVisinu() << " P=" << DajPovrsinu()
              << " V=" << DajZapreminu();
  }
};

int main() {
  Krug k(5);
  k.Ispisi();
  std::cout << std::endl;
  Valjak v1(1, 9);
  v1.Ispisi();
  std::cout << std::endl;
  v1.DajBazu().Ispisi();
  std::cout << std::endl;
  Valjak v2(k.DajPoluprecnik(), 8);
  v2.DajBazu().Ispisi();
  std::cout << std::endl;
  return 0;
}