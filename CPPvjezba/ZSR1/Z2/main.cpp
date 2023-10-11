//TP 2018/2019: ZSR 1, Zadatak 2
#include <iostream>
#include <iomanip>

constexpr double milja= 1.852;

using namespace std;

int main ()
{
    cout<<"Unesite brzinu broda u cvorovima: ";
    int cvorovi;
    cin>>cvorovi;
    double brzlik;
    brzlik=cvorovi*milja;
    cout<<"Brzina broda u km/h je "<<setprecision(2)<<fixed<<brzlik<<"km/h.";
	return 0;
}