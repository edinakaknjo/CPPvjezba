//TP 2018/2019: ZSR 7, Zadatak 4
#include <iostream>
#include <map>

using namespace std;

string monoalfabetski(string pocetni , map<char, char> slova){
    
    for(int i=0; i<pocetni.length(); i++){
        auto iterator=slova.find(pocetni.at(i));
        if(iterator!=slova.end()) pocetni.at(i)= iterator->second;
    }

    return pocetni;
}

int main ()
{
    map<char,char> zamjena{{'A','a'}, {'B','b'}};
    string s="AaaaaBBBBBcdef";
    string vraceni=monoalfabetski(s, zamjena);
    cout<<vraceni;
	return 0;
}