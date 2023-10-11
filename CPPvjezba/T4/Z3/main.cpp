//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void UMala(string &rijec){
    for(int i=0; i<rijec.size();i++){
    char slovo=rijec.at(i);
    rijec.at(i)=std::tolower(slovo);
}
}

void IzdvojiKrajnjeRijeci(vector<string> rijeci, string &prvapoabc, string &zadnjapoabc){

vector<string> original=rijeci;
int mjprve=-1, mjzadnje=-1;

for(int i=0; i<rijeci.size();i++){
    UMala(rijeci.at(i));
}

for(int i=0; i<rijeci.size();i++){
    if(i==0){
        zadnjapoabc=rijeci.at(i);
        prvapoabc=rijeci.at(i);
        mjprve=i;
        mjzadnje=i;
        continue;
    }
    if(rijeci.at(i)<prvapoabc){
        prvapoabc=rijeci.at(i);
        mjprve=i;
    }
    if(rijeci.at(i)>zadnjapoabc){
        zadnjapoabc=rijeci.at(i);
        mjzadnje=i;
    }
}

if(mjprve!=-1){prvapoabc=original.at(mjprve);}
if(mjzadnje!=-1){zadnjapoabc=original.at(mjzadnje);}
}

void ZadrziDuplikate(vector<string> &rijeci){
    vector<string> ponavljajuse;
    bool preskoci;
    for(int i=0; i<int(rijeci.size()-1); i++){
        for (int j=i+1; j<rijeci.size(); j++){
            if(rijeci.at(i)==rijeci.at(j)){
                preskoci=false;
                for(int k=0; k<ponavljajuse.size(); k++){
                    if((ponavljajuse.at(k)==rijeci.at(i))){
                        preskoci=true; break;
                    }
                }
                if(preskoci==true)
                continue;
                ponavljajuse.push_back(rijeci.at(i));
            }
        }
    }
    rijeci=ponavljajuse;
}
int main(){
    cout<<"Koliko zelite unijeti rijeci: ";
    int n;
    cin>>n;
     cin.ignore(1000, '\n');
    cout<<"Unesite rijeci: "<<endl;
    
    vector<string>rijeci(n);
    
        for(int i=0; i<n; i++){
           
            getline(cin,rijeci.at(i));
           
        }
         cin.clear();
    cin.ignore(1000,'\n');
    
    string prva;
    string zadnja;
    IzdvojiKrajnjeRijeci(rijeci, prva, zadnja);
    cout<<"Prva rijec po abecednom poretku je: "<<prva<<endl<<"Posljednja rijec po abecednom poretku je: "<<zadnja<<endl;
    
    ZadrziDuplikate(rijeci);
    cout<<"Rijeci koje se ponavljaju su: ";
    for(int i=0; i<rijeci.size(); i++){
        cout<<rijeci.at(i)<<" ";
    }
    return 0;
}