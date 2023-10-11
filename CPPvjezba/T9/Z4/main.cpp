
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Sat{
    int sati, min, sek;

    public:

    static bool DaLiJeIspravno(int sati, int min, int sek){
        if(sati<0 || sati>23) return false;
        if(min>59 || min<0) return false;
        if(sek>59 || sek<0) return false;
        return true;

    }


    int DajSate() const { return sati;}
    int DajMinute() const { return min;}
    int DajSekunde() const { return sek;}

    
    void Postavi(int sati, int min, int sek);
    void PostaviNormalizirano(int sati, int min, int sek);

    Sat &Sljedeci(){
        sek++;
        PostaviNormalizirano(sati, min,sek);
        return *this;}
    
    Sat &Prethodni(){
        sek--;
        PostaviNormalizirano(sati, min,sek);
        return *this;

    }

    Sat &PomjeriZa(int broj){
        sek+=broj;
        PostaviNormalizirano(sati, min,sek);
        return *this;

    }

    void Ispisi() const{
        cout<<setw(2)<<setfill('0')<<sati<<":"<<setw(2)<<setfill('0')<<min<<":"<<setw(2)<<setfill('0')<<sek;
    }

    friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
        int sekundeprvog, sekundedrugog;
        sekundeprvog=s1.sati*3600+ s1.min*60 +s1.sek;
        sekundedrugog=s2.sati*3600+ s2.min*60 +s2.sek;
        int sekizmedju;
        sekizmedju=abs(sekundeprvog-sekundedrugog);

        return sekizmedju;

    }

    static int Razmak(const Sat &s1, const Sat &s2);

};

void Sat::Postavi(int sati, int min, int sek){
    if(!DaLiJeIspravno(sati, min, sek)) throw domain_error("Neispravno vrijeme!");
    Sat::sati=sati; Sat::min=min; Sat::sek=sek;
}

void Sat::PostaviNormalizirano(int sati, int min, int sek){
    while(sek>59){
        min++;
        sek-=60;
    }
    while(min>59){
        sati++;
        min-=60;
    }
    while(sek<0){
        min--;
        sek+=60;
    }
    while(min<0){
        sati--;
        min+=60;
    }
    while(sati>23){
        sati-=24;
    }
    while(sati<0){
        sati+=24;
    }

    Sat::sati=sati; Sat::min=min; Sat::sek=sek;

}

int Sat::Razmak(const Sat &s1, const Sat &s2){
    int sekundeprvog, sekundedrugog;
        sekundeprvog=s1.sati*3600+ s1.min*60 +s1.sek;
        sekundedrugog=s2.sati*3600+ s2.min*60 +s2.sek;
        int sekizmedju;
        sekizmedju=abs(sekundeprvog-sekundedrugog);

        return sekizmedju;
}


int main ()
{
    Sat s;
  s.PostaviNormalizirano(-2, 3, 10);
  s.Ispisi(); std::cout << std::endl;
  s.Sljedeci().Ispisi();
  std::cout << std::endl;
  s.Sljedeci().Sljedeci().Ispisi();
  std::cout << std::endl;
  s.Prethodni().Ispisi();
  std::cout << std::endl;
  s.Prethodni().Prethodni().Ispisi();
  std::cout << std::endl;
  s.PomjeriZa(5).Ispisi(); std::cout << std::endl;

  s.Postavi(10,10,10);
  std::cout << s.DajSate() << " "
            << s.DajMinute() << " "
            << s.DajSekunde();

	return 0;
}