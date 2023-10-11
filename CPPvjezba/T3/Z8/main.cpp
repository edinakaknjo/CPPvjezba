//TP 2018/2019: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int BrojRijeci(string recenica){
    int brrijeci=0;
    for(int i=0;i<recenica.length(); i++){
        if(recenica[i]!=' ' && recenica[i+1]==' ') 
            brrijeci++;
        }
    

    return brrijeci;
}

string IzdvojiRijec(string recenica, int br){

    
    int br1(recenica.length()), brojac=0, poc=(-1), kraj=(-1);
    bool razmak(true);

    if(br<=0 || BrojRijeci(recenica)<br) {throw br; }/*range_error("IZUZETAK: Pogresan broj rijeci!");*/
 
    for(int i=0;i<recenica.length();i++){
        if(recenica[i]!=' ' && razmak==true)
        {brojac++;
        razmak=false;
        if(brojac==br){poc=i;}}

        if(recenica[i]==' ' && razmak==false){
            razmak=true;
            if(poc!=(-1)){kraj=i; break;}}
        }
    
    string rijec=recenica.substr(poc,kraj-poc);

    return rijec;
}


int main ()
{   
    int n;
    cout<<"Unesite redni broj rijeci: ";
    cin>>n;
    cin.clear();
    cin.ignore(1000,'\n');

    
    cout<<"Unesite recenicu: ";
    string recenica;
    

    getline(cin,recenica);

    string rijec;

   try{
    rijec=IzdvojiRijec(recenica,n);}
    catch(int n){
        cout<<"IZUZETAK: Pogresan redni broj rijeci!";
        return 0;
    }

    cout<<"Rijec na poziciji "<<n<<" je ";
    cout<< rijec;

	return 0;
}