//TP 2018/2019: ZSR 1, Zadatak 1
#include <iostream>

using namespace std;

int main ()
{
    int sat1, min1, sek1;
    cout<<"Unesite prvo vrijeme (h min s): ";
    cin>>sat1;
    cin>>min1;
    cin>>sek1;
    cout<<"Unesite drugo vrijeme (h min s): ";
    int sat2, min2, sek2;
    cin>>sat2;
    cin>>min2;
    cin>>sek2;
    int brojsekundi1;
    int brojsekundi2;
    brojsekundi1=sek1+min1*60+ sat1*3600;
    brojsekundi2=sek2+min2*60+ sat2*3600;
    int razlika;
    razlika=(brojsekundi2-brojsekundi1);
    if(razlika<0) razlika*=(-1);
    int brojsati=0, ostatak, brojsekundi=0, brojmin=0;

    if(razlika>=3600){
        ostatak=razlika%3600;
        brojsati=razlika/3600;

        if(ostatak>60){
            brojsekundi=ostatak%60;
            
            brojmin=ostatak/60;
        }
    }

    if(razlika<3600 && razlika>=60){
       
        brojsekundi=razlika%60;
        
        brojmin=razlika/60;

    }
    
    if(razlika<60) brojsekundi=razlika;

    cout<<"Izmedju ova dva trenutka proteklo je "<<brojsati<<"h "<<brojmin<<"min "<<brojsekundi<<"s.";
	return 0;
}