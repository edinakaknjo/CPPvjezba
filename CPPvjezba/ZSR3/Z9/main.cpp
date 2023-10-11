//TP 2018/2019: ZSR 3, Zadatak 9
#include <iostream>
#include <vector>

using namespace std;

vector<double> indeksi(vector<double>a, vector<int> b){
    int brojel=a.size();
    for(int i=0; i<b.size(); i++){
        if(b.at(i)>=brojel || b.at(i)<0 ) {
            throw range_error("vel br");
        }
    }

    vector<double> vraceni;

        for(int j=0; j<b.size(); j++){
            int mjesto=b.at(j);
            double el= a.at(mjesto);
            vraceni.push_back(el);
        }
    

    return vraceni;
}

int main ()
{
    vector<int>b{3,4,2,1};
    vector<double>a{2.34 ,1, 45.6, 4,3,0, 46};
    vector<double> vr;
    vr=indeksi(a,b);
    for(int i=0; i<vr.size(); i++){
        cout<<vr.at(i)<<" ";
    }
	return 0;
}