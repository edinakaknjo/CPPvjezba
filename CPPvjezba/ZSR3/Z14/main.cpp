//TP 2018/2019: ZSR 3, Zadatak 14
#include <iostream>
#include <vector>

using namespace std;

template<typename Tip>

bool ImaStacionaran(vector<vector<Tip>> matrica){
    for(int i=0; i<matrica.size(); i++){
        for(int j=0; j<matrica.at(i).size(); j++){
            if(i!=0 && j!=0 && (i+1)!=matrica.size() && (j+1)!=matrica.at(i).size()){
                if(matrica.at(i).at(j)== matrica.at(i-1).at(j) && matrica.at(i).at(j)==matrica.at(i+1).at(j) &&
                matrica.at(i).at(j)==matrica.at(i).at(j-1) && matrica.at(i).at(j)==matrica.at(i).at(j+1)) return true;
            }
        }
    }
    return false;
}

int main ()
{
    vector<vector<int>> matrica{{1,3,7,8},{1,7,7,7},{0,3,7,9}};
    cout<<boolalpha<<ImaStacionaran(matrica);
	return 0;
}