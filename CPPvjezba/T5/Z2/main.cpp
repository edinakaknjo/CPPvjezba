
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename it1, typename it2>

it1 RazmijeniBlokove (it2 pocprvog, it2 krajprvog, it1 pocdrugog){
    while(pocprvog!=krajprvog){
        auto pomocna=*pocprvog;
        *pocprvog=*pocdrugog;
        *pocdrugog=pomocna;
        pocprvog++;
        pocdrugog++;
    }

    return pocdrugog;
}


int main ()
{   
    int niz1[3] {1, 2, 3};
    int niz2[3] {10,20,30};

    RazmijeniBlokove(niz1, std::end(niz1), niz2);

    cout<<"Kontejner 1 glasi: "<<niz1<< "Kontejner 2 glasi: "<< niz2;
	return 0;
}