//TP 2018/2019: Tutorijal 3, Zadatak 5
#include <iostream>
#include <deque>
#include <cmath>
#include <limits>


using namespace std;


int SaberiCif(int a){
    int sum=0;
    do{
        int cif;
        cif=(a%10);
        a/=10;
        sum+=cif;
    }while(a!=0);
    sum=abs(sum);

    return sum;
}

deque<int> IzdvojiElemente(deque<int> br, bool parni){
    deque<int> v;
    for(int el:br){
        if((SaberiCif(el)%2==0 && parni) || ( SaberiCif(el)%2!=0 && !parni))
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


    for (int j=v2.size()-1; j>=0; j--) {
        
        cout<<v2.at(j);
        if(j!=0)cout<<",";
        
        }
    
    cout<<endl;

        
    for (int i=v3.size()-1; i>=0; i--) {
        cout<<v3.at(i);
        if(i!=0)cout<<",";
        
        }
    cout<<endl;

}