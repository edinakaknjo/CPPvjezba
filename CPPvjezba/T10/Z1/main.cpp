
#include <iostream>
#include <stdexcept>


constexpr double epsilon=1e-14;

using namespace std;


class StedniRacun{

double iznos=0;
public:

StedniRacun(double iznos){
    Postavi(iznos);
}

void Postavi(double iznos){
    if(iznos<epsilon) throw logic_error("Nedozvoljeno pocetno stanje");

    this->iznos=iznos;
}

void Ulozi(double ulog){
    
    if(ulog<epsilon) throw logic_error("Transakcija odbijena");
    this->iznos+=ulog;
}

void Podigni(double uzimanje){
    if(uzimanje>iznos) throw logic_error("Transakcija odbijena");
    this->iznos-=uzimanje;
}

double DajStanje()const{
    return this->iznos;
}

void ObracunajKamatu(double procent){
    if(procent<epsilon) throw logic_error("Nedozvoljena kamatna stopa");
    this->iznos+=this->iznos/100 *procent;
    
}

};
int main ()

{
	return 0;
}