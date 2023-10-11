//TP 2018/2019: ZSR 3, Zadatak 45
#include <iostream>
#include <string>

using namespace std;

bool samoglasnik(char s){
    s=toupper(s);
    if(s=='A' || s=='E' || s=='I' || s=='O' || s=='U') return true;
    else return false;
}

string rec(string recenica){
    for(int i=0; i<recenica.size(); i++){
        char slovo=recenica.at(i);
        if(samoglasnik(slovo)){
            string sat="p";
            sat.push_back(slovo);

            recenica.insert(i+1,sat);
            i+=2;
        }
    }
    return recenica;
}

int main ()
{
    cout<<rec("dobar dan");
	return 0;
}