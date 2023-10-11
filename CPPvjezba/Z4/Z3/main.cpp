// TP 2018/2019: Zadaća 4, Zadatak 3
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>
#include <new>

using namespace std;

vector<int> daniumjesecu{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Datum {

  int dan, mj, god;

public:
  Datum(int dan, int mj, int god) { Postavi(dan, mj, god); }
  void Postavi(int dan, int mj, int god);

  tuple<int, int, int> Ocitaj() {
    tuple<int, int, int> vraceni = make_tuple(dan, mj, god);
    return vraceni;
  }

  void Ispisi() const { cout << dan << "/" << mj << "/" << god; }
};

void Datum::Postavi(int dan, int mj, int god) {
  if (mj < 1 || mj > 12)
    throw domain_error("Neispravan datum");

  if (dan < 1 || dan > (daniumjesecu.at(mj)))
    throw domain_error("Neispravan datum");

  this->dan = dan;
  this->mj = mj;
  this->god = god;
}

class Vrijeme {

  int sati, minute;

public:
  Vrijeme(int sati, int minute) { Postavi(sati, minute); }
  void Postavi(int sati, int minute);

  pair<int, int> Ocitaj() {
    pair<int, int> vraceni = make_pair(sati, minute);
    return vraceni;
  }

  void Ispisi() const {
    if (sati < 10 && minute < 10)
      cout << "0" << sati << ":0" << minute;
    else if (sati < 10 && minute >= 10)
      cout << "0" << sati << ":" << minute;
    else if (sati >= 10 && minute < 10)
      cout << sati << ":0" << minute;
    else
      cout << sati << ":" << minute;
  }
};

void Vrijeme::Postavi(int sati, int minute) {
  if (sati < 0 || sati > 24 || minute < 0 || minute > 59)
    throw domain_error("Neispravno vrijeme");

  this->sati = sati;
  this->minute = minute;
}

class Pregled {

  string ime;
  Datum nekidatum;
  Vrijeme nekovrijeme;

public:
  Pregled(const string &ime, const Datum &nekidatum, const Vrijeme &nekovrijeme)
      : ime(ime), nekidatum(nekidatum), nekovrijeme(nekovrijeme){};
  Pregled(const string &ime, int dan, int mjesec, int godina, int sati,
          int minute)
      : ime(ime), nekidatum(dan, mjesec, godina), nekovrijeme(sati, minute){};

  void PromjeniPacijenta(const string &ime) { this->ime = ime; }
  void PromjeniDatum(const Datum &novidatum) { this->nekidatum = novidatum; }
  void PromjeniVrijeme(const Vrijeme &novovrijeme) {
    this->nekovrijeme = novovrijeme;
  }

  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();

  string DajImePacijenta() const { return ime; }
  Datum DajDatumPregleda() const { return nekidatum; }
  Vrijeme DajVrijemePregleda() const { return nekovrijeme; }

  friend bool DolaziPrije(const Pregled &prvipregled,
                          const Pregled &drugipregled);

  void Ispisi() const {
    cout << left << setw(30) << setfill(' ') << ime;
    nekidatum.Ispisi();
    cout << " ";
    nekovrijeme.Ispisi();
    cout << endl;
  }
};


void Pregled::PomjeriDanUnaprijed() {
  tuple<int, int, int> ovajdan = nekidatum.Ocitaj();
  try {
    nekidatum.Postavi(get<0>(ovajdan) + 1, get<1>(ovajdan), get<2>(ovajdan));
  } catch (...) {
    try {
      nekidatum.Postavi(1, get<1>(ovajdan) + 1, get<2>(ovajdan));
    } catch (...) {
      nekidatum.Postavi(1, 1, get<2>(ovajdan) + 1);
    }
  }
}

void Pregled::PomjeriDanUnazad() {
  tuple<int, int, int> ovajdan = nekidatum.Ocitaj();
  if (get<0>(ovajdan) == 1) {
    if (get<1>(ovajdan) == 1) {
      nekidatum.Postavi(31, 12, get<2>(ovajdan) - 1);
    } else {
      int maxdana = 31;
      bool moze = false;
      while (!moze) {
        try {
          nekidatum.Postavi(maxdana--, get<1>(ovajdan) - 1, get<2>(ovajdan));
          moze = true;
        } catch (...) {
        }
      }
    }
  } else {
    nekidatum.Postavi(get<0>(ovajdan) - 1, get<1>(ovajdan), get<2>(ovajdan));
  }
}

bool DolaziPrije(const Pregled &prvipregled, const Pregled &drugipregled){
    tuple<int,int,int> datumprvog=prvipregled.DajDatumPregleda().Ocitaj();
    tuple<int,int,int> datumdrugog=drugipregled.DajDatumPregleda().Ocitaj();

    pair<int,int>vrijemeprvog=prvipregled.DajVrijemePregleda().Ocitaj();
    pair<int,int>vrijemedrugog=drugipregled.DajVrijemePregleda().Ocitaj();

    if(get<2>(datumprvog)!= get<2>(datumdrugog)) {return get<2>(datumprvog)< get<2>(datumdrugog);}
    else if(get<1>(datumprvog) !=get<1>(datumdrugog)){ return get<1>(datumprvog)< get<1>(datumdrugog);}
    else if(get<0>(datumprvog) != get<0>(datumdrugog)){ return get<0>(datumprvog)< get<0>(datumdrugog);}
    else if(vrijemeprvog.first != vrijemedrugog.first){ return vrijemeprvog.first <vrijemedrugog.first; }
    else {return vrijemeprvog.second < vrijemedrugog.second;}

}

class Pregledi{

    int maxbrojpregleda, brojtrenutnih;
    Pregled** vektorpok;

    public:
    explicit Pregledi(int maxbrojpregleda):maxbrojpregleda(maxbrojpregleda), brojtrenutnih(0),vektorpok(new Pregled*[maxbrojpregleda]{}){};

    Pregledi(std::initializer_list<Pregled> spisakpregleda);
    ~Pregledi(){
        for(int i=0; i<maxbrojpregleda; i++) delete vektorpok[i];
        delete[] vektorpok;};
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const string &ime, const Datum &nekidatum, const Vrijeme &nekovrijeme);
    void RegistrirajPregled(  const string &ime, int dan, int mj, int god, int sati, int minute);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const{return brojtrenutnih;};
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const string &ime);
    void IspisiPregledeNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisakpregleda){

    vektorpok=new Pregled*[spisakpregleda.size()];
    try{
        for(int i=0; i<spisakpregleda.size(); i++){
            vektorpok[i]=new Pregled(*(spisakpregleda.begin()+i));
        }
    }
    catch(...){
        for(int i=0; i<spisakpregleda.size(); i++) delete vektorpok[i];
        delete[] vektorpok;
        throw;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi): maxbrojpregleda(pregledi.maxbrojpregleda),brojtrenutnih(pregledi.brojtrenutnih),
vektorpok(new Pregled*[maxbrojpregleda]){
    try{
        for(int i=0; i<brojtrenutnih; i++){
            vektorpok[i]=new Pregled(*pregledi.vektorpok[i]);
        }
    }
    catch(...){
        for(int i=0; i<maxbrojpregleda; i++) delete vektorpok[i];
        delete[] vektorpok;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi): maxbrojpregleda(pregledi.maxbrojpregleda), brojtrenutnih(pregledi.brojtrenutnih),
vektorpok(pregledi.vektorpok){
    pregledi.vektorpok=nullptr;
    pregledi.maxbrojpregleda=0;
}

Pregledi &Pregledi:: operator=(const Pregledi &pregledi){
    if(&pregledi !=this){
        for(int i=0; i<maxbrojpregleda; i++) delete vektorpok[i];
        delete[] vektorpok;
        maxbrojpregleda=pregledi.maxbrojpregleda;
        brojtrenutnih=pregledi.brojtrenutnih;
        vektorpok=new Pregled*[maxbrojpregleda]{};
        for (int i=0; i<brojtrenutnih; i++){
            vektorpok[i]=new Pregled(*pregledi.vektorpok[i]);
        }
    }
    return *this;
}

Pregledi &Pregledi::operator= (Pregledi &&pregledi){
    if(&pregledi!=this){
        for(int i=0; i<maxbrojpregleda; i++) delete vektorpok[i];
        delete[] vektorpok;
        maxbrojpregleda=pregledi.maxbrojpregleda;
        brojtrenutnih=pregledi.brojtrenutnih;
        vektorpok=pregledi.vektorpok;
        pregledi.vektorpok=nullptr;
        pregledi.maxbrojpregleda=0;
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const string &ime, const Datum &nekidatum , const Vrijeme &nekovrijeme){
    if(brojtrenutnih>=maxbrojpregleda) throw range_error("Dostignut maksimalni broj pregleda");
    vektorpok[brojtrenutnih++]=new Pregled(ime, nekidatum, nekovrijeme);
}

void Pregledi::RegistrirajPregled(const string &ime, int dan, int mj, int god, int sati, int minute){
    if(brojtrenutnih>=maxbrojpregleda) throw range_error("Dostignut maksimalni broj pregleda");
    vektorpok[brojtrenutnih++]=new Pregled(ime, dan, mj, god,sati, minute);
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(brojtrenutnih>=maxbrojpregleda) {
        delete pregled;
        throw range_error("Dostignut maksimalni broj pregleda");}
        vektorpok[brojtrenutnih++]=pregled;
}

Pregled &Pregledi::DajNajranijiPregled(){
    if(brojtrenutnih==0) throw domain_error("Nema registriranih pregleda");
    return **min_element(vektorpok, vektorpok+brojtrenutnih, [](Pregled* neki, Pregled* nekidrugi){
        return DolaziPrije(*neki, *nekidrugi);
    });
}

void Pregledi::IspisiPregledeNaDatum(Datum &datum)const{
    Pregled** pompregled=new Pregled*[brojtrenutnih];
    for(int i=0; i<brojtrenutnih; i++){
        pompregled[i]=new Pregled(vektorpok[i][0]);
    }

    sort(pompregled, pompregled+brojtrenutnih, [](Pregled *prvi, Pregled *drugi){
        if(!DolaziPrije(*prvi,*drugi)) return false;
        else return true;
    });

    for (int i=0; i<brojtrenutnih; i++){
        tuple<int,int,int> nadjenidat=pompregled[i][0].DajDatumPregleda().Ocitaj();
        tuple<int, int, int> zadanidat=datum.Ocitaj();
        if(get<0>(nadjenidat)==get<0>(zadanidat) && get<1> (nadjenidat) == get<1>(zadanidat) && get<2>(nadjenidat)==get<2>(zadanidat)){
            pompregled[i][0].Ispisi();
        }
    }

    for(int i=0; i<brojtrenutnih; i++)delete pompregled[i];
    delete[] pompregled;
    pompregled=nullptr;
}

void Pregledi::IspisiSvePreglede() const{
    sort(vektorpok, vektorpok+brojtrenutnih, [](Pregled *neki, Pregled *nekidrugi){ return DolaziPrije(*neki, *nekidrugi);});
    for(int i=0; i<brojtrenutnih; i++){
        vektorpok[i]->Ispisi();
    }
}


void Pregledi::IsprazniKolekciju(){
    for(int i=0; i<brojtrenutnih; i++){
        delete[] vektorpok[i];
    }
    delete[] vektorpok;
    brojtrenutnih=0;
    vektorpok=nullptr;

    vektorpok=new Pregled*[maxbrojpregleda];
}

void Pregledi::ObrisiNajranijiPregled(){
    if(brojtrenutnih==0) throw range_error("Prazna kolekcija");

    Pregled najraniji=vektorpok[0][0];
    int indeks=0;
    for(int i=1; i<brojtrenutnih; i++){
        if(DolaziPrije(vektorpok[i][0], najraniji)){
            najraniji=vektorpok[i][0];
            indeks=i;
        }
    }

    delete vektorpok[indeks];
    vektorpok[indeks]=nullptr;

    int i=indeks+1;

    while(i<brojtrenutnih){
        vektorpok[i-1]=vektorpok[i];
        i++;
    }

    brojtrenutnih-=1;
}

void Pregledi::ObrisiPregledePacijenta(const string &ime){
    for(int i=0; i<brojtrenutnih; i++){
        if(vektorpok[i][0].DajImePacijenta()==ime){
            int it=i+1;
            if(it==(brojtrenutnih-1)){
                delete vektorpok[it];
                brojtrenutnih--;
                break;
            }
            else{
                delete vektorpok[i];
                vektorpok[i]=nullptr;

            }

            while(it<brojtrenutnih){
                vektorpok[it-1]=vektorpok[it];
                it++;
            }
            brojtrenutnih--;
        }
    }
}

int main() { 
    cout<<"Unesite maksimalan broj pregleda"<<endl;
    int maksbrojpregleda;
    cin>>maksbrojpregleda;
    
    initializer_list<Pregledi> svi{};
    int i=0;
    while(1){
        cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa:"<<endl;
        string ime;
        cin>>ime;
        if(ime=="kraj"){
            break;
        }
        cout<<"Unesite dan, mjesec i godinu pregleda:"<<endl;
        int dan, mj, god;
        cin>>dan;
        cin>>mj; 
        cin>>god;
        cout<<"Unesite sate i minute pregleda:"<<endl;
        int sati, minute;
        cin>>sati;
        cin>>minute;
    
        Pregled p{ime, dan, mj, god, sati, minute};
        

    }
    return 0; }