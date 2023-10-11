//TP 2018/2019: ZSR 3, Zadatak 55
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool JeLiRijec(char x){
    return x!=' ';
}

vector<string> Rijeci(string recenica){
    bool razmak=true;
    vector<string> rijeci;
    for(int i=0; i+1<recenica.size(); i++){
        if(!JeLiRijec(recenica.at(i))) razmak=true;
        else if(razmak){
            int pocetak=i;
            while(i<recenica.size() && JeLiRijec(recenica.at(i))) i++;
            int duzina=i-pocetak;
            rijeci.push_back( recenica.substr(pocetak, duzina));
        
        razmak=false;
        i=pocetak;
        }
    }
    return rijeci;
}

int main ()
{
    string s="ja   se   zovem edina.";

    vector<string> r=Rijeci(s);
    for(int i=0; i<r.size(); i++){
        cout<<r.at(i)<<" ";
    }
	return 0;
}