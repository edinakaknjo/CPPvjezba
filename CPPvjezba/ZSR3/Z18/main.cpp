//TP 2018/2019: ZSR 3, Zadatak 18

#include <iostream>
#include <deque>

using namespace std;

template <typename Tip>
bool DaLiJeCirkulantna(deque<deque<Tip>> mat)
{
    //PRAZNA
    if(mat.size()==0) return false;
    //NEMA FORMU MATRICE
    for(int i=0; i+1<mat.size(); i++) if(mat.at(i).size() != mat.at(i+1).size()) return false;
    
    //PROVJERA 
    for(int i=0; i+1<mat.size(); i++ ) {
        for(int j=0; j+1<mat.at(i).size(); j++) {
            //ako se NE radi o ZADNJOJ KOLOni
            if(j<(mat.at(i).size()-1) &&  mat.at(i).at(j)!=mat.at(i+1).at(j+1))
                return false;
            //ako se radi O ZADNJOJ KOLONI
            else if(j==(mat.at(i).size()-1) && mat.at(i).at(j)!=mat.at(i+1).at(0))
                return false;

        }
    }
    return true;
}

int main()
{
    deque<deque<int>> mat{ {1,2,3,4}, {4,1,2,3}, {3,4,1,2}};
    cout<<boolalpha<<DaLiJeCirkulantna(mat)<<endl;
    
    //NEMA SVAKI RED ISTO ELEMENATA MORA BITI FALSE
    deque<deque<int>> mat2{ {1,2,4}, {4,1,2,3}, {3,4,1,2}};
    cout<<boolalpha<<DaLiJeCirkulantna(mat2)<<endl;
    
        
    //NEMA SVAKI RED ISTO ELEMENATA MORA BITI FALSE
    deque<deque<int>> mat3;
    cout<<boolalpha<<DaLiJeCirkulantna(mat3)<<endl;
    
}
