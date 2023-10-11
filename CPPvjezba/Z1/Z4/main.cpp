//TP 2018/2019: Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool JeLiRijec(char znak){
    return znak!=' ';
}

void KadSuIste( string &rec,int poc, string zamjena){
    int i=0;
   while(poc<rec.length() && i<zamjena.length()){
        rec.at(poc)=zamjena.at(i);
        poc++;
        i++;
    }
}

int DuzinaRijeci(string rijec){
    int duzina;
    duzina=rijec.length();
    return duzina;
}

string ZamjenaRijeci(string recenica, vector<string> original, vector<string> zamjena){

    if(original.size()!=zamjena.size()){
        throw domain_error("Nekorektni parametri");
    }
    bool razmak=true;

    for(int i=0; i<recenica.size(); i++){
        if(!JeLiRijec(recenica.at(i))) razmak=true;
        else if(razmak){
            int poc=i;
            while(i<recenica.size() && JeLiRijec(recenica.at(i))) i++;
            int duzinaorig=i-poc;
            for(int j=0; j<original.size(); j++){
                if(recenica.substr(poc, duzinaorig)==original.at(j)){
                    string rijeczamj=zamjena.at(j);
                    int duzinazamj;
                    if(!rijeczamj.empty()) duzinazamj=rijeczamj.length();
                    else duzinazamj=0;
                    if(duzinaorig>rijeczamj.length()){
                        recenica.erase(recenica.begin()+poc+duzinazamj, recenica.begin()+poc+duzinaorig);
                    }
                    else if(duzinaorig<duzinazamj) recenica.insert(recenica.begin()+poc+duzinaorig, duzinazamj-duzinaorig, 'a');
                    KadSuIste(recenica, poc, rijeczamj);
                }
                i=poc;
                razmak=false;
            }
        }
    }
    return recenica;

}

int main ()
{  
    try{
    cout<<"Unesite koliko riječi sadrži rječnik."<<endl;
    int brojrijeci;
    cin>>brojrijeci;
    vector<string> original;
    vector<string> zamjena;

    for(int i=0; i<brojrijeci; i++){
        cout<<"Unesite "<<i+1<<". original rječnika."<<endl;
        string orijec;
        cin>>orijec;
        original.push_back(orijec);

        cout<<"Unesite "<<i+1<<". zamjenu rječnika."<<endl;
        string zrijec;
        cin>>zrijec;
        zamjena.push_back(zrijec);
    }

    do{
    cout<<endl<<"Unesite rečenicu koju želite transformisati: "<<endl;
    string recenica;
   if(char(cin.peek())=='\n'){
        cin.get();
    }
    getline(cin,recenica);
    if(recenica.length()==0){
        break;
    }
    cout<<"Transformisana rečenica glasi: "<<endl;
    string zamjenjena=ZamjenaRijeci(recenica, original, zamjena);
 
        cout<<zamjenjena;} while(1);
    }
    catch (domain_error e){
    cout<<e.what();
    }

	return 0;
}