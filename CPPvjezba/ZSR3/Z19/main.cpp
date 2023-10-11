// TP 2018/2019: ZSR 3, Zadatak 19
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> kvadratmat(vector<vector<int>> mat) {
  vector<vector<int>> produkt(mat.size(), vector<int>(mat.size(),0));

  

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat.size(); j++) {
      for (int k = 0; k < mat.size(); k++) {
        produkt.at(i).at(j) =
            produkt.at(i).at(j) + (mat.at(i).at(k) * mat.at(k).at(j));
      }
    }
  }
  return produkt;
}

bool Idempotentna(vector<vector<int>> mat) {
  vector<vector<int>> kvadrat = kvadratmat(mat);
  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat.size(); j++) {
      if (mat.at(i).at(j) != kvadrat.at(i).at(j))
        return false;
    }
  }
  return true;
}

int main() {
  vector<vector<int>> mat{{4,-1}, {12,-3}};
  cout << boolalpha << Idempotentna(mat);
  return 0;
}