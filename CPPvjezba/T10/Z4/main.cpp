
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

class Ugao{

    double radijani;
    double pi=4*atan(1);

    public:

    static int Stepeni(double radijani);
    static int Minute(double radijani);
    static int Sekunde(double radijani);
    static double Pretvori(int step, int min, int sek);
    
    Ugao(double radijani){
        Postavi(radijani);
    }

    void Postavi(double radijani){
        radijani=(radijani*180)/pi;
        while(radijani>360) radijani-=360;
        while(radijani<0) radijani+=360;
        this->radijani=radijani;
    }
    
     Ugao(int step, int min, int sek){
        Postavi(step, min, sek);
    }
    void Postavi(int step, int min, int sek){
        double radijani=Pretvori(step, min, sek);
        while(radijani>360) radijani-=360;
        while(radijani<0) radijani+=360;
        radijani=(radijani*pi)/180,
        this->radijani=radijani;
    }

    double DajRadijane() const{
        return this->radijani;
    }

    int DajStepene() const{
        return this->Stepeni(radijani);
    }
    
    int DajMinute() const{
        return this->Minute(radijani);
    }
    
    int DajSekunde() const{
        return this->Sekunde(radijani);
    }

    void Ispisi() const{
        cout<<fixed<<setprecision(5)<<DajRadijane();
    }

    void IspisiKlasicno() const
	{
		cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";
	}

    void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde);

    Ugao &SaberiSa(const Ugao &u);
    Ugao &PomnoziSa(double x);
    friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
    friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);

};

double Ugao::Pretvori(int step, int min, int sek){
    double temp=(((sek/60.)+min)/60.)+step;
    return temp;
}

Ugao &Ugao::SaberiSa(const Ugao &u){
    radijani=this->radijani+u.DajRadijane();

}

Ugao &Ugao::PomnoziSa(double x){
    Ugao rad;
    rad=this->radijani*x;
    this->radijani=rad.DajRadijane();
}



int main ()
{
	return 0;
}