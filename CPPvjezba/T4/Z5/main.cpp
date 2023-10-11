//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename tipvek>

vector<tipvek> Presjek(vector<tipvek> v1, vector<tipvek> v2){
    vector<tipvek> v3;
    bool preskoci;
    for( int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(v1.at(i)==v2.at(j)){
                preskoci=false;
                for(int k=0; k<v3.size(); k++){
                    if(v3.at(k)==v1.at(i)){
                        preskoci=true;
                        break;
                    }
                }
                if(preskoci==true) continue;
                v3.push_back(v1.at(i));
            }
        }
    }
    return v3;
}

int main ()
{
    cout<<"Test za realne brojeve..."<<endl;
    cout<<"Unesite broj elemenata prvog vektora: ";
    int br1;
    cin>>br1;
    cin.clear();
    cin.ignore(1000,'\n');

    vector<double>v1r;
    cout<<"Unesite elemente prvog vektora: ";
    for(int i=0; i<br1; i++){
        double el;
        cin>>el;
        v1r.push_back(el);
    }
    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"Unesite broj elemenata drugog vektora: ";
    int br2;
    cin>>br2;
    vector<double>v2r;
    cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<br2; i++){
        double el2;
        cin>>el2;
        v2r.push_back(el2);
    }
    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"Zajednicki elementi su: ";
    vector<double> v3r=Presjek(v1r, v2r);
    for(int i=0; i<v3r.size(); i++){
        cout<<v3r.at(i)<<" ";
    }

    cout<<endl;

    cout<<endl<<"Test za stringove..."<<endl;
    cout<<"Unesite broj elemenata prvog vektora: ";
    int broj1;
    cin>>broj1;
    cin.clear();
    cin.ignore(1000,'\n');
    vector<string>v1s;
    cout<<"Unesite elemente prvog vektora (ENTER nakon svakog unosa):"<<endl;
    for(int i=0; i<broj1; i++){
        string rijec;
        getline(cin,rijec);
        v1s.push_back(rijec);
    }
    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"Unesite broj elemenata drugog vektora: ";
    int broj2;
    cin>>broj2;
     cin.clear();
    cin.ignore(1000,'\n');
    vector<string>v2s;
    cout<<"Unesite elemente drugog vektora (ENTER nakon svakog unosa):"<<endl;
    for(int i=0; i<broj2; i++){
        string rijec2;
        getline(cin,rijec2);
        v2s.push_back(rijec2);
    }
    cin.clear();
    cin.ignore(1000,'\n');

    cout<<"Zajednicki elementi su: "<<endl;
    vector<string> v3s=Presjek(v1s, v2s);
    for(int i=0; i<v3s.size(); i++){
        cout<<v3s.at(i)<<" ";
    }
	return 0;

    
}