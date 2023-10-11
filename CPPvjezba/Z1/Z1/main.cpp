// TP 2018/2019: Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



void Ponavljanje (vector<int> &v){

    vector<int>vraceni;

    for(int i=0; i<v.size(); i++){
            bool elementseponavlja=false;
            for(int j=0; j<i; j++){
                if(v.at(j)==v.at(i)){
                    elementseponavlja=true;
                    break;
                }
            }
        if(elementseponavlja==false) vraceni.push_back(v.at(i));
    }
    v=vraceni;
}


int ProCif(int a){
    int proizcifara=1;
    if(a<0) a=a*(-1);
    do{
        int cif=a%10;
        a=a/10;
        proizcifara=proizcifara*cif;
    }while(a>=1);

return proizcifara;
}

int MultiplaBroja (int n){
    int multiplaotpornost=0;
    if(abs(n)>=10){


       do{
            n=ProCif(n);
            multiplaotpornost++;
        }while (n>=10);

}
    return multiplaotpornost;
}

enum class Kriterij {Veca, Manja, Jednaka};

vector<int> IBSZMU (vector<int> zadani, int prag, Kriterij kriterij){
    
    vector<int> v;
    vector<int> veci;
    vector<int> manji;
    vector<int> jednaki;

    for(int el:zadani){
        int mult=MultiplaBroja(el);

        if(mult>prag){
            veci.push_back(el);
        }
        else if(mult<prag){
            manji.push_back(el);
        }
        else if(mult==prag){
            jednaki.push_back(el);
        }

        if(kriterij==Kriterij::Veca){v=veci;}
        else if(kriterij==Kriterij::Manja){v=manji;}
        else if(kriterij==Kriterij::Jednaka){v=jednaki;}
    }

    Ponavljanje(v);

    return v;
}

int main() {
    vector<int>unesenivek;
    int el;
    cout<<"Unesite slijed brojeva (0 za kraj): ";
    do{
        cin>>el;
        if(el==0) break;
        unesenivek.push_back(el);
        
    }while(el!=0);

    int prag;
    cout<<"Unesite zeljeni prag za multiplikativnu otpornost: ";
    cin>>prag;
    cout<<endl;

    vector<int>veci=IBSZMU(unesenivek, prag, Kriterij::Veca);
    vector<int>manji=IBSZMU(unesenivek, prag, Kriterij::Manja);
    vector<int>jednaki=IBSZMU(unesenivek, prag, Kriterij::Jednaka);

    cout<<"Brojevi cija je multiplikativna otpornost manja od zadane: ";
    if(manji.size()==0){
        cout<<"Nema takvih brojeva";
    }
    else{
       for(int i=0; i<manji.size(); i++){
             cout<<manji.at(i)<<" ";
        
    }}
    cout<<endl;

    cout<<"Brojevi cija je multiplikativna otpornost veca od zadane: ";
    if(veci.size()==0){
        cout<<"Nema takvih brojeva ";
    }
    else{
    for(int i=0; i<veci.size(); i++){
         cout<<veci.at(i)<<" ";
        
    }}
    cout<<endl;

    cout<<"Brojevi cija je multiplikativna otpornost jednaka zadanoj: ";
    if(jednaki.size()==0){
        cout<<"Nema takvih brojeva ";
    }
    else{
    for(int i=0; i<jednaki.size(); i++){
        cout<<jednaki.at(i)<<" ";
        
    }}

    cout<<endl;
     return 0; 
     }