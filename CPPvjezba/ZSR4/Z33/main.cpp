//TP 2018/2019: ZSR 4, Zadatak 33
#include <iostream>
#include <string>

using namespace std;

char Umanjiznak(char x){
    x=x+1;
    return x;
}

void Umanji(string &rijec){
    for(int i=0; i<rijec.size(); i++){
        rijec.at(i)=Umanjiznak(rijec.at(i));
    }
}
int main ()
{
    string s="PROBA";
    Umanji(s);
    cout<<s;
	return 0;
}