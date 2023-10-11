
#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

template<typename Iter>

auto SumaBloka( Iter poc, Iter kraj) -> decltype(*poc+*poc){
    if(poc==kraj) throw range_error("Blok je prazan");
    decltype(*poc+*poc) suma{};
    while(poc!=kraj){
        suma+=*poc;
        poc++;
    }
    return suma;
}
int main ()
{
    try{
        deque<double> dek(0);
        auto suma=SumaBloka(dek.begin(), dek.end());
        
    }
    catch(range_error e){
        cout<<e.what()<<endl;
    }
    
    
	return 0;
}