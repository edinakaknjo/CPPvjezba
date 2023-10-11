//TP 2018/2019: Zadaća 2, Zadatak 5
#include <iostream>
#include <new>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int BrojSlova(string neki){
    int velicina=0;
    for(int i=0; neki.at(i)!='\0'; i++){
        velicina++;
    }
    return velicina;
}

void PotencijalniKrivci(char ** &dinamicki, vector<string> imena){
    int brojpok=imena.size();
    dinamicki=new char*[brojpok];
    try{
        for(int i=0; i<brojpok; i++){
            string rijec=imena.at(i);
            int brslova=imena.at(i).size();
            dinamicki[i]=new char[brslova];
            for(int j=0; j<brslova; j++){
                dinamicki[i][j]=rijec.at(j);
            }
        }
    }
    catch(bad_alloc){
        for(int i=0; i<brojpok; i++) delete[] dinamicki[i];
        delete[] dinamicki;
        throw;
    }

}

void OdbaciOptuzbu(char** &dinamicki, int velniza, string imepotencijalnog){
    bool imaga=false;
    int brojistih=0;
    for(int i=0; i<velniza; i++){
       for(int j=0; j<imepotencijalnog.size(); j++){
            if(dinamicki[i][j]==imepotencijalnog.at(j)){
                brojistih++;
            }
         }
         if(brojistih==imepotencijalnog.size()) {
            imaga=true;
            break;
         }
     }
     if(!imaga) throw domain_error("Osoba sa imenom ");
    
    
}

int main ()
{
    try{
        cout<<"Unesite broj ljudi koji su optuzeni za prepisivanje/prodavanje zadaca: ";
        int brojljudi;
        cin>>brojljudi;
        vector<string> vekimena;

        for(int i=0; i<brojljudi; i++){
            string ime;
            getline(cin,ime);
            cin.ignore(1000, '\n');

            vekimena.push_back(ime);
        }

        char** nizljudi=new char*[brojljudi];
        PotencijalniKrivci(nizljudi, vekimena);


    }
    catch(bad_alloc){
        cout<<"Nedovoljno memorije!";
    }
    /*string rijec;
    cin>>rijec;
    int vel;
    vel=BrojSlova(rijec);
    cout<< " vel je "<<vel;*/
    
	return 0;
}