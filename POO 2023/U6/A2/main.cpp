#include <iostream>
#include "RecursosHumanos.h"

int main (int argc, char *argv[])
{
    RecursosHumanos ema;
    Persona aux;
    aux = {{"Sasuke Uchiha"},{10},{10},{100}};

    for(int i = 0; i < 10; ++i){

        ema.CargarPersonas(aux);
    }
    std::cout <<"TAmanio: "<<ema.VerTamanio();

    std::string n = "./emanuel.bin";
    if(ema.Guardar(n)) std::cout <<"\nSeGuado\n";
    else std::cout <<"No se guardo\n";

    if(ema.Leer(n)) std::cout <<"Se Leyo\n";
    else std::cout <<"No se leyo\n";
    std::cout <<"Tamanio: "<<ema.VerTamanio()<<"\n";
    for(int i = 0; i < ema.VerTamanio(); ++i){
        std::cout <<ema.VerNombre(i)<<"\n";
    }
    return 0;
}
