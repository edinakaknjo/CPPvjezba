// TP 2018/2019: ZSR 3, Zadatak 21
#include <iostream>
#include <vector>

using namespace std;

bool SavrsenKvadrat(vector<vector<int>> mat) {
  for (int i = 0; i < mat.size(); i++) {
    if (mat.size() != mat.at(i).size())
      return false;
  }
  int n = mat.size();

  int zbird1 = 0, zbird2 = 0;

  for (int i = 0; i < n; i++) {
    zbird1 += mat.at(i).at(i);
  }

  for (int i = 0; i < n; i++) {
    zbird2 += mat.at(i).at(n - 1 - i);
  }

  if (zbird1 != zbird2)
    return false;

  for (int i = 0; i < n; i++) {
    int zbirred = 0;
    for (int j = 0; j < n; j++) {
      zbirred += mat.at(i).at(j);
    }
    if (zbirred != zbird1)
      return false;
  }

  for (int i = 0; i < n; i++) {
    int zbirkol = 0;
    for (int j = 0; j < n; j++) {
      zbirkol += mat.at(j).at(i);
    }
    if (zbirkol != zbird1)
      return false;
  }

  vector<int> brojaci(n*n,0);

    for(int i=0; i<mat.size(); i++) {
        for(int j=0; j<mat.size(); j++) {
            if(mat.at(i).at(j)<1 || mat.at(i).at(j)>n*n) {  
                return false;
            }
            brojaci.at(mat.at(i).at(j)-1) ++;
        }
    }

    for(int el: brojaci) {
        if(el>1) return false;
    }

  

  return true;
}

int main() {
  vector<vector<int>> mat{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
  cout <<boolalpha<< SavrsenKvadrat(mat);
  return 0;
}