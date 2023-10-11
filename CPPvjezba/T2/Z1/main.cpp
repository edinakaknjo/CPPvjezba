//TP 2020/2021: Tutorijal 2, Zadatak 1

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

constexpr double epsilon= 0.00000001;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sqrt;
using std::fabs;
using std::numeric_limits;

bool DaLiJeProst (int n){
    int k=sqrt(n);
    if(n<2)
    {return false;}

    for(int i=1; i<=k; i++)
        {if (i!=1 && n%i==0)
             return false;}
    
    return true;
}

vector <int> ProstiBrojeviUOpsegu (int a,int b){

    vector<int> v;
    int i;
    for (i=a; i<=b; i++)
        { if(DaLiJeProst(i))
            v.push_back(i);
        
        if (i==numeric_limits<int>::max()) break; }    

    return v;
}


int main(){
    int a,b;
    cout<<"Unesite pocetnu i krajnju vrijednost: "<<endl;
    cin>>a>>b;
    vector<int> v=ProstiBrojeviUOpsegu(a,b);
    if(v.size()==0)
        cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!"<<endl;
    else
        cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";

    for(int i=0; i<v.size(); i++)
    {cout<<v.at(i);
    if(i!=v.size()-1)
        cout<<", ";}
    cout<<endl;
}

