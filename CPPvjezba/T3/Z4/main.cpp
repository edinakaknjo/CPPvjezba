#include <iostream>
#include <deque>
#include <cmath>
#include <limits>


using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::fabs;


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

deque<int> IzdvojiElemente(deque<int> br, bool parni){
    deque<int> v;
    for(int el:br){
        if((parni && SaberiCif(el)%2==0) || (!parni && SaberiCif(el)%2!=0))
            v.push_front(el); 
    }
    return v;
}

int main ()
{
    
    cout<<"Koliko zelite unijeti elemenata: ";
    int elem;
    cin>>elem;
    if(elem<=0){
        cout<<"Broj elemenata mora biti veci od 0!";
        return 0;
    }
    deque<int> v(elem);
    cout<<"Unesite elemente: ";
    for(int i=0; i<elem; i++){
        int broj;
        cin>>v.at(i);
         
        
    }

    deque<int> v2=IzdvojiElemente(v, true);
    deque<int> v3=IzdvojiElemente(v,false);


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