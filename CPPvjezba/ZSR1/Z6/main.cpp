//TP 2018/2019: ZSR 1, Zadatak 6
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    cout<<"Unesite tri broja: ";
    double a, b,c;
    bool moze=false;

    cin>>a>>b>>c;

    if(a==sqrt(pow(b,2)+pow(c,2))) moze=true;
    else if(b==sqrt(pow(c,2)+pow(a,2))) moze=true;
    else if(c==sqrt(pow(a,2)+pow(b,2))) moze=true;

    if(moze) cout<<"Mogu biti stranice pravouglog!";
    else cout<<"Ne mogu biti stranice pravouglog!";
	return 0;
}