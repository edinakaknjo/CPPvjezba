//TP 2018/2019: ZSR 1, Zadatak 3
#include <iostream>

constexpr double malac=0.000000001;

using namespace std;

int main ()
{
    cout<<"Unesite podacic";
    double brojcic;
    cin>>brojcic;

    bool prirodan=false, cijeli=false, realan=false;

    if(brojcic>=0) prirodan=true;
    if(brojcic-int(brojcic)<malac) cijeli=true;
    else realan=true; 

    if(prirodan || cijeli || realan){

        if(prirodan) cout<<"Podatak je prirodan broj."<<endl;
        if(cijeli && !prirodan) cout<<"Cijeli broj, ali nije prirodan"<<endl;
        if( cijeli && prirodan) cout<<"Cijeli broj i prirodan"<<endl;
        if(realan) cout<<"Realan broj ali nije cijeli."<<endl;
        }

    else cout<<"Podatak nije broj";

    

	return 0;
}