//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef map<string, vector< string>> Knjiga;

map<string, tuple<string, int, int>> KreirajIndeksPojmova(Knjiga neka){
    auto it=neka.begin();
    map<string, tuple<string, int, int>> mapaindeksa;
    int velmape=0;
    for(auto ovopog=it; ovopog!=neka.end(); ovopog++){
        vector<string> ovastr= ovopog->second;
        for(int i=0; i<ovastr.size(); i++){
            string sadrzaj=ovastr.at(i);
            

        }
    }
}


int main ()
{
	return 0;
}