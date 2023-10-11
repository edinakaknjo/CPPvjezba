
#include <iostream>
#include <list>

using namespace std;

template<typename Tip>

list<Tip> SortirajListu(list<Tip> &lista){
    for(auto it=lista.begin(); it!=lista.end(); it++){
        auto min=it;
        for(auto it2=it; it2!=lista.end(); it2++){
            if(*it2< *min) min= it2;
        }
        if(min!=it) swap(*min, *it);
    }

    return lista;

}
int main ()
{
    cout<<"Koliko ima elemenata: "<<endl;
    int n;
    cin>>n;
    cout<<"Unesite elemente: "<<endl;
    list<int> lista;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        lista.push_back(el);
    }
    list<int> vracena=SortirajListu(lista);
    cout<<"Sortirana lista: ";
    for(auto it=vracena.begin(); it!=vracena.end(); it++){
    
        cout<<*it<<" ";
    }
	return 0;
}