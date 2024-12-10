#include <iostream>
#include <algorithm>
#include <list>

template<class EMA>
EMA generar();

template<class EMA>
bool dosmay_up(std::list<EMA> &);

typedef struct{

    std::string nombre;
    int edad;

}Datos;

bool operator < (const Datos &, const Datos &);
bool operator > (const Datos &, const Datos &);
bool operator == (const Datos &, const Datos &);
bool MayorDatos(const Datos &, const Datos &);
bool dosmay_up(std::list<Datos>&lista);

int main (){

    std::list<int>numeros(10);

    std::generate(numeros.begin(), numeros.end(), generar<int>);

    for(const auto x : numeros) std::cout <<x<<" ";

    if(dosmay_up<int>(numeros)) std::cout<<"\nSon iguales\n";

    else std::cout <<"\nSon distintos\n";

    for(const auto x : numeros) std::cout <<x<<" ";

    std::cout <<"\n";

    std::list<float>numeros2(10);

    std::generate(numeros2.begin(), numeros2.end(), generar<float>);

    for(const auto x : numeros2) std::cout <<x<<" ";

    if(dosmay_up<float>(numeros2)) std::cout<<"\nSon iguales\n";

    else std::cout <<"\nSon distintos\n";

    for(const auto x : numeros2) std::cout <<x<<" ";

    return 0;
}

bool operator < (const Datos &a, const Datos &b){
    return a.edad < b.edad ? true : false;
}

bool operator > (const Datos &a, const Datos &b){
    return a < b ? false : true;
}

bool operator == (const Datos &a, const Datos &b){
    return not (a < b) and not (a > b) ? true : false;
}

bool MayorDatos(const Datos &a, const Datos &b){
    return a > b ? true : false;
}

bool dosmay_up(std::list<Datos>&lista){

    auto max1 = std::max_element(lista.begin(), lista.end(), MayorDatos);

    auto aux = *max1;

    *max1 = *lista.begin();

    *lista.begin() = aux;

    auto max2 = std::max_element(std::next(lista.begin()), lista.end(), MayorDatos);

    aux = *max2;

    *max2 = *std::next(lista.begin());

    *std::next(lista.begin()) = aux;

    return *lista.begin() == *std::next(lista.begin()) ? true : false;

}

template<class EMA>
EMA generar(){return rand() % ((99-3) + 3) / 3.3;}

template <class EMA>
bool dosmay_up(std::list<EMA> &lista){

    auto max1 = std::max_element(lista.begin(), lista.end());

    auto aux = *max1;

    *max1 = *lista.begin();

    *lista.begin() = aux;

    auto max2 = std::max_element(std::next(lista.begin()), lista.end());

    aux = *max2;

    *max2 = *std::next(lista.begin());

    *std::next(lista.begin()) = aux;

    return *lista.begin() == *std::next(lista.begin()) ? true : false;

}
