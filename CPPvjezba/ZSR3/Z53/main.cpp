//TP 2018/2019: ZSR 3, Zadatak 53
#include <iostream>
#include <string>

using namespace std;

bool ImaLiZnaka(string rijec, char znak, int &index){
    for(int i=0; i<rijec.size(); i++){
        if(rijec.at(i)==znak) {
            index=i;
            i++;
            return true;}
    }
    return false;
}

string IzbrisiPodstring(string rijec, string pods){
    string vraceni;
        for(int j=0; j<pods.size(); j++){
            int index;
            if(ImaLiZnaka(rijec, pods.at(j), index)){
                rijec.erase(index,1);
            }
        }
        vraceni=rijec;

        return vraceni;
    
}

int main ()
{
    string s1="abcdefg";
    string s2="bde";
    string vraceni=IzbrisiPodstring(s1, s2);
    cout<<vraceni;
	return 0;
}