#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef struct{

    std::string nombre;
    float precio;
}Datos;

bool operator<(const Datos &, const Datos &);
bool operator>(const Datos &a, const Datos &b);

template<class EMA>
std::tuple<EMA,EMA>dosmin_down(std::vector<EMA>&);

bool comparar(const Datos &a, const Datos &b);
std::tuple<Datos,Datos>dosmin_down(std::vector<Datos>&);


int main(){

    std::vector<float>numeros;

    std::vector<std::string>palabras;

    float a,b;

    std::tie(a,b) = dosmin_down<float>(numeros);

    std::string c,d;

    std::tie(c,d) = dosmin_down<std::string>(palabras);


    return 0;

}


template<class EMA>
std::tuple<EMA,EMA>dosmin_down(std::vector<EMA>&dato){

    std::sort(dato.begin(),dato.end());

    return std::make_tuple(dato[0],dato[1]);
}
bool operator<(const Datos &a, const Datos &b){

    return a.precio < b.precio ? true : false;
}

bool operator>(const Datos &a, const Datos &b){
    return a < b ? false : true;
}
bool comparar(const Datos &a, const Datos &b){
    return a < b ? true : false;
}

std::tuple<Datos,Datos>dosmin_down(std::vector<Datos>&dato){
    
    std::sort(dato.begin(),dato.end(), comparar);
    
    return std::make_tuple(dato[0],dato[1]);

}
