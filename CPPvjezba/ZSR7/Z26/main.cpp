//TP 2018/2019: ZSR 7, Zadatak 26
#include <algorithm>
#include <iostream>
#include <list>
#include <string>


using namespace std;

bool NeAlfa(char znak) {
  return (znak <'0' || znak > '9' && znak < 'A' || znak > 'Z' && znak < 'a' || znak>'z');
}

bool ImaVise(string rec) {
  int brojac = 0;
  for (auto i = rec.begin(); i < rec.end(); i++) {
    if (NeAlfa(*i))
      brojac++;
  }

  return (brojac > 7);
}



int main() { 
    list<string> pocetna;
    for(int i=0; i<10; i++){
        string jedan;
        getline(cin, jedan);
        pocetna.push_back(jedan);
    }

    transform(pocetna.begin(), pocetna.end(), pocetna.begin(), [](string s){
        if(ImaVise(s)) s="";
        return s;
    });
    int brojac=1;
    for(auto it=pocetna.begin(); it!=pocetna.end(); it++){
        
        cout<<*it<<" "<<brojac++<<endl;
        
    }
    return 0; }