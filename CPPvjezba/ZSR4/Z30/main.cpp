//TP 2018/2019: ZSR 4, Zadatak 30
#include <iostream>
#include <string>

using namespace std;

void Analizastringa( string rec, int &brojslova, int &brojcif, int &brojostalog){
    brojslova=0;
    brojcif=0;
    brojostalog=0;
    for(int i=0; i<rec.size(); i++){
        char znak=rec.at(i);
        if(znak>='A' && znak<='z') brojslova++;
        else if(znak>='0' && znak<='9') brojcif++;
        else brojostalog++;
    }
}

int main ()
{
    string rec="sa4521kj.8h";
    int brojsl, brojcif, brojo;
    Analizastringa(rec, brojsl, brojcif, brojo);
    cout<<brojsl<< " "<< brojcif<<" "<< brojo;

	return 0;
}