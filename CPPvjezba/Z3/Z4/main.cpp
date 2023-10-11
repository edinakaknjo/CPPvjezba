// TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<int> Razbrajanje(int N, int M) {
  list<int> blokovi;
  for (int i = 1; i <= N; i++) {
    blokovi.push_back(i);
  }

  vector<int> redosljed;

  int korak = M;

  /*while (blokovi.begin() != blokovi.end()) {*/
    for (auto it = blokovi.begin(); it != blokovi.end(); it++) {

      if ((it++) != blokovi.end()) {
        if (korak == 0)
          korak = M;
        if (korak == M) {
          redosljed.push_back(*it);
          blokovi.erase(it);
        }
        korak--;
      }

      if ((it++) == blokovi.end()) {
        if (korak == M) {
          redosljed.push_back(*it);
          blokovi.erase(it);
          korak--;
          it = blokovi.begin();
        }

        else {
          korak = M - korak;
          it = blokovi.begin();
        }
      }
    }
  /*}*/
  return redosljed;
}

int OdabirKoraka(int N, int K){
    vector<int> rasporeduovomsluc;
    int potrebnikorak=0;

    for(int i=1; i<=N; i++){
        rasporeduovomsluc=Razbrajanje(N, i);
        if(rasporeduovomsluc.at(N-1)==K) {
            potrebnikorak=i;
            break;
        }
    }
    return potrebnikorak;
}


int main() {
  /*vector<int> v;
  v = Razbrajanje(10, 4);

  for (int i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }   TEST ZA RAZBRAJANJE */


  return 0;
}