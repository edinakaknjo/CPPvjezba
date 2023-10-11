//TP 2018/2019: ZSR 4, Zadatak 35
#include <iostream>
#include <string>

using namespace std;

constexpr int lowerA=97;
constexpr int lowerM=109;
constexpr int lowerN=110;
constexpr int lowerZ=122;


constexpr int upperA=65;
constexpr int upperM=77;
constexpr int upperN=78;
constexpr int upperZ=90;

bool JeLiRijec(char x){
    return (x>=65 && x<=122);
}

char VratiROT(char x){
    if(JeLiRijec(x)){
        if(x>=65 && x<=77) x=x+13;
        else if(x>=97 && x<=109) x=x+13;
        else if(x>=110 && x<=122) x=x-13;
        else if(x>=78 && x<=90) x=x-13;
    }
    return x;
}

void ROT13(string &rec){
    for(int i=0; i<rec.size(); i++){
        rec.at(i)=VratiROT(rec.at(i));
    }
}

int main ()
{   
    string r="ABc67D";
    ROT13(r);
    cout<<r;
	return 0;
}