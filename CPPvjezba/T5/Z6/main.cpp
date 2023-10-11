
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int SumaCif (int br){
    static int suma=0;
   
    if(br!=0)
    return (abs(br)%10+SumaCif(br/10));
}

bool Posumi(int x, int y){
    int suma1=SumaCif(abs(x));
    int suma2=SumaCif(abs(y));
    if(suma1==suma2) return x<y;
    return suma1<suma2;
}

void unos(int &el){
    cin>>el;
}

void ispis(int el){
    cout<<el<<" ";
}

int main ()
{   
    cout<<"Unesite broj elemenata: ";
    int n;
    cin>>n;
    vector<int> v1(n);
    cout<<"Unesite elemente: ";
    for_each(v1.begin(), v1.end(),unos);
    sort(v1.begin(), v1.end(), Posumi);
    cout<<"Niz sortiran po sumi cifara glasi: ";
    for_each(v1.begin(), v1.end(), ispis);
    cout<<endl;
    cout<<"Unesite broj koji trazite: ";
    int broj;
    cin>>broj;
    vector<int>::iterator trbroj=std::lower_bound(v1.begin(), v1.end(), broj, Posumi);
    if(*trbroj==broj) cout<<"Trazeni broj nalazi se na poziciji "<<trbroj-v1.begin();
    else
    cout<<"Trazeni broj ne nalazi se u nizu!";
	return 0;
}