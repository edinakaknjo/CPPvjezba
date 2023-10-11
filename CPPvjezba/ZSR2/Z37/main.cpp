//TP 2018/2019: ZSR 2, Zadatak 37
#include <iostream>
#include <deque>

using namespace std;

int Medijan(deque<int> dek){
    int brojel=dek.size();
    int sredina=brojel/2;
    int medijan;
    for(int i=0; i<brojel; i++){
        int broj=dek.at(i);
        int brojac=0;
        for(int j=0; j<brojel; j++){
            if(dek.at(j)>broj) brojac++;
        }
    if(brojac==sredina) {
        medijan=broj;
        break;}
    }
    return medijan;
}

int main ()
{
    deque<int> d{1,25,9,37,81,24,15,93,21};
    cout<<Medijan(d);
	return 0;
}