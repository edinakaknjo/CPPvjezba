//TP 2018/2019: Zadaća 2, Zadatak 3
#include <asm-generic/errno.h>
#include <iostream>
#include <deque>
#include <array>

using namespace std;

template < class Iter1, class Iter2, class Iter3>


auto ZajednickiElementiBlokova(Iter1 p1, Iter1 p2, Iter2 p3,Iter2 p4,Iter3 p5){
    int velprvog=0, veldrugog=0;
    while(p1!=p2){
        p1++;
        velprvog++;
    }
    while(p3!=p4){
        p3++;
        veldrugog++;
    }
    int velrezultata=0;

    bool preskoci;
    for( int i=0; i<velprvog; i++){
       for(int j=0; j<veldrugog; j++){
           if(p1+i==p3+j){
               preskoci=false;
               if(velprvog>veldrugog){
                    for(int k=0; k<velprvog; k++){
                        if((p5+k)==(p1+i)){
                             preskoci=true;
                            break;
                         }
                     }
                }
           if(velprvog<veldrugog){
                    for(int k=0; k<veldrugog; k++){
                        if((p5+k)==(p1+i)){
                             preskoci=true;
                            break;
                         }
                     }
                }
           }
           if(preskoci==true) continue;
           { /*stavi u taj blok*/
           velrezultata++;
           }
        }
    }
    return (p5+velrezultata);
}


int main ()
{
    cout<<"Unesi broj elemenata niza"<<endl;
    int br1;
    cin>>br1;
    cout<<"Unesi elemente niza"<<endl;

    array<int, br1> niz;
    for(int i; i<br1; i++){
        cin>>
        niz.at(i);
    }

    cout<<"Unesi broj elemenata deka"<<endl;
    int br2;
    cin>>br2;
    cout<<"Unesi elemente niza"<<endl;

    deque<int> dek;
    for(int i; i<br1; i++){
        int el;
        cin>>el;
        dek.push_back(el);
    }

    
    cout<<"Vektor zajednickih elemenata niza i deka ima"<<"elemenata"<<endl;
    cout<<"Zajednicki elementi glase: ";

    /*isprintaj nekako el odzada jer je zadnji poslan pa vamo*/

	return 0;
}