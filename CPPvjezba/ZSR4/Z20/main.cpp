//TP 2018/2019: ZSR 4, Zadatak 20
#include <iostream>
#include <vector>

using namespace std;

void minimax(vector<vector<double>> &matrica, double &minimax,
             double &maximin) {

  for (int i = 0; i+1 < matrica.size(); i++) {
    if (matrica.at(i).size() != matrica.at(i + 1).size())
      throw domain_error("Nema formu matrice");
  }

  int najmanji, najveci;

  for (int i = 0; i < matrica.size(); i++) {
    najmanji = matrica.at(i).at(0);
    najveci = matrica.at(i).at(0);

    for (int j = 0; j < matrica.at(i).size(); j++) {
      if (matrica.at(i).at(j) > najveci)
        najveci = matrica.at(i).at(j);
      if (matrica.at(i).at(j) < najmanji)
        najmanji = matrica.at(i).at(j);
    }
    if (i == 0 || najveci < minimax)
      minimax = najveci;
    if (i == 0 || najmanji > maximin)
      maximin = najmanji;
  }
}

int main() { 
    double a, b;
    vector<vector<double>> mat{{2, 3,5,8}, {4, 7,8,2}, {3,2,2,1}};
    minimax(mat, a,b);
    cout<<a<<b;
    return 0; }