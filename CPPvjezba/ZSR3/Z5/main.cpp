//TP 2018/2019: ZSR 3, Zadatak 5
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double RezKorjena(vector<int> brojevi){
    double rez=0;
    int brojel=brojevi.size();
    for(int i=brojel-1; i>=0; i--){
        rez=sqrt(brojevi.at(i)+sqrt (rez));

    }

    return rez;
}

int main ()
{
    vector<int> br{9,8,11,4,12};
    cout<<RezKorjena(br);
	return 0;
}