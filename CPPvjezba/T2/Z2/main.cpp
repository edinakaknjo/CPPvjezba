//TP 2020/2021: Tutorijal 2, Zadatak 2
#include <iostream>
#include <cmath>
#include <vector>

constexpr double EPSILON = 1e-15;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::fabs;


bool TestPerioda (vector<double>v, int p ){

    if(p>=v.size() || p<=0)
    {
        return false;
    
    }
    for (int i=0; i+p<v.size(); i++){
        if(fabs(v.at(i)-v.at(i+p))>EPSILON)
            return false;
    }
    return true;
}

int OdrediOsnovniPeriod (vector<double>a){
    
    for(int i=1; i<a.size(); i++){
        if(TestPerioda(a,i))
            return i;
    }
    return 0;

}

int main ()
{
    double x;
    vector<double> a;
    cout<<"Unesite slijed brojeva (0 za kraj): ";
    do{
        
        cin>> x;
        if(fabs(x)<EPSILON)
            break;
        else
            a.push_back(x);
    }while(1);
    
    if(OdrediOsnovniPeriod(a)==0)
        cout<<"Slijed nije periodican!"<<endl;
    else
        cout<<"Slijed je periodican sa osnovnim periodom "<<OdrediOsnovniPeriod(a)<<"."<<endl;
    
    
}
