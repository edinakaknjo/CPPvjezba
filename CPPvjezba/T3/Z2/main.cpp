#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int SaberiCif(int a){
    int sum=0;
    do{
        int cif;
        cif=abs(a%10);
        a/=10;
        sum+=cif;
    }while(int(a)!=0);

    return sum;
}

vector<int> IzdvojiElemente(vector<int> br, bool parni){
    vector<int> v;
    for(int el:br){
        if((parni && SaberiCif(el)%2==0) || (!parni && SaberiCif(el)%2!=0))
            v.push_back(el); 
    }
    return v;
}

int main ()
{
    vector<int> v;
    cout<<"Koliko zelite unijeti elemenata: ";
    int elem;
    cin>>elem;
    if(elem<=0){
        cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    cout<<"Unesite elemente: ";
    for(int i=0; i<elem; i++){
        int broj;
        cin>>broj;
        v.push_back(broj);
    }

    auto v2=IzdvojiElemente(v, true);
    auto v3=IzdvojiElemente(v,false);
    if(v2.size()==0)cout<<endl;
    if(v3.size()==0)cout<<endl;

    for (int j=0; j<v2.size(); j++) {
        cout<<v2.at(j);
        if(j<v2.size()-1)cout<<",";
        
        }
    
    cout<<endl;

        
    for (int i=0; i<v3.size(); i++) {
        cout<<v3.at(i);
        if(i<v3.size()-1)cout<<",";
        
        }
    cout<<endl;

	return 0;
}