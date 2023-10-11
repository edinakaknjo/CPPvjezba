//TP 2018/2019: ZSR 3, Zadatak 47
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool JeLiRijec(char x){
    return x!=' ';
}

void UMala(string &rijec){
    for(int i=0; i<rijec.size();i++){
    char slovo=rijec.at(i);
    rijec.at(i)=std::tolower(slovo);
}
}


bool DaLiJePalindrom(string recenica){
    vector<char> slova1;
    vector<char> slova2;
    UMala(recenica);

    for(int i=0; i<recenica.size(); i++){
      
        if(JeLiRijec(recenica.at(i))) {
            slova1.push_back(recenica.at(i));
            slova2.push_back(recenica.at(i));
        }
    }

    for(int i=0; i<slova1.size(); i++){
        if(slova1.at(i)!=slova2.at(slova1.size()-1-i)) return false;
    }

return true;

}
int main ()
{
    string s="kAPak";
    cout<<boolalpha<<DaLiJePalindrom(s);
	return 0;
}