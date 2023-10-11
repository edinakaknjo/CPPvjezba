//TP 2018/2019: ZSR 4, Zadatak 53
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Kronekerov( vector<int> a, vector<int> b){
    vector<vector<int>> kroneker(a.size(), vector<int>(b.size()));

    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            kroneker.at(i).at(j)=a.at(i)*b.at(j);
        }
    }

    return kroneker;
}

int main ()
{
    vector<int> a{3, -1, 0, 5};
    vector<int> b{4,3,15,0, -5, 2};
    vector<vector<int>> produkt= Kronekerov(a,b);

    for(int i=0; i<produkt.size(); i++){
        for(int j=0; j<produkt.at(i).size(); j++){
          cout<<produkt.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
	return 0;
}