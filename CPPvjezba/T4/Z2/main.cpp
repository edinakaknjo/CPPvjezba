//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

using namespace std;

void IzvrniString( string &recenica){
    for(int i=0; i<recenica.length()/2; i++){
        char pomocna=recenica.at(i);
        recenica.at(i)=recenica.at(recenica.length()-i-1);
        recenica.at(recenica.length()-i-1)=pomocna;
    }

}

int main ()
{   
    string unesenarec;
    cout<<"Unesi string: ";
    getline(cin, unesenarec);
    cout<<"Izvrnuti string je: ";
    IzvrniString(unesenarec);
    cout<<unesenarec;
	return 0;
}