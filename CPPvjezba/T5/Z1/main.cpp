
#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{   
    char recenica[1000];
    cout<<"Unesite recenicu: ";
    cin.getline(recenica, sizeof recenica);
    cout<<"Recenica bez prve rijeci glasi: ";
    char *p=recenica;
    int brojac=0;
    bool razmak=true;
    while(*p!='\0'){
        if(*p==' ') razmak=true;
        else if(razmak){
            brojac++;
            if(brojac==2) break; //dosl do 2. rj
            razmak=false;
        }
        p++;
    }
    cout<<p<<endl;
	return 0;
}