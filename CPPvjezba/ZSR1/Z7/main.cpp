//TP 2018/2019: ZSR 1, Zadatak 7
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int glavnica, stopa, kamata, svota;

    cout<<"Unesite glavnicu: "<<endl;
    cin>>glavnica;
    cout<<"Unesite stopu: "<<endl;
    cin>>stopa;

    stopa/=100;

    kamata=glavnica*stopa;
    svota=glavnica+kamata;

    cout<<std::left<<setw(25)<<"Glavnica:"<<setfill(' ')<<std::right<<glavnica<<endl;
    cout<<std::left<<setw(25)<<"Kamatna stopa:"<<setfill(' ')<<std::right<<stopa<<endl;
    cout<<std::left<<setw(25)<<"Kamate:"<<setfill(' ')<<std::right<<kamata<<endl;
    cout<<std::left<<setw(25)<<"Nova svota:"<<setfill(' ')<<std::right<<svota<<endl;
    
	return 0;
}