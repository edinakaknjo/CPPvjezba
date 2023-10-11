//TP 2018/2019: ZSR 3, Zadatak 15
#include <iostream>
#include <vector>

using namespace std;

bool Tranzitivna(vector<vector<bool>> mat){

    for(int i=0; i+1<mat.size(); i++){
        if(mat.at(i).size()!=mat.at(i+1).size()) throw domain_error("Nema oblik kvadratne ");
    }

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){
            if(mat.at(i).at(j)==true){
                for(int k=0; k<mat.size(); k++){
                    if(mat.at(j).at(k)==true && mat.at(i).at(k)!=true) return false;
                    
                }
            }
        }
    }
    return true;
}

int main ()
{   
    vector<vector<bool>> v{{true, false, true}, {true, true, false}, {true, false, true}};
    cout<<boolalpha<<Tranzitivna(v);
	return 0;
}