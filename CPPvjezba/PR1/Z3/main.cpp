//TP 2018/2019: Ispit 1, Zadatak 3
#include <iostream>
#include <new>
#include <string>

using namespace std;

bool JeLiRijec(char x){
    return (x!=' ');
}

string* ObrniRijeci(string* recenica){
     string* izvrnuti;
     izvrnuti= new char[1000];
     try{
     for(int i=1; i<1000; i++){
         if(JeLiRijec(recenica[i]) && !JeLiRijec(recenica[i-1])){
             

         }
     }}
     catch(bad_alloc){
         delete[] izvrnuti;
     }
}

int main ()
{
	return 0;
}