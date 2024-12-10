#include <iostream>
#include <string>
#include "Clinica.h"

void CargarClinica(Clinica &ema){
    for(int i = 1; i < 7; ++i){
        for(int e = 0 ; e < 5; ++e ){
            ema.AgregarPaciente(std::to_string(i), rand() % (99)+ 10000);
        }
    }
}
int main (){
    Clinica ema; 

    CargarClinica(ema);

    for(int i = 1; i < 7; ++i){
        std::vector<long>aux = ema.Pacientes(std::to_string(i));
        std::cout <<"Medioco : "<<i<<"\n";
        for(const long &x : aux){
            std::cout<<"DNI: "<<x<<"\n";
        }
    }
    long x;
    std::cout <<"Eliminar paciente: ";std::cin>>x;
    ema.Eliminar(x);

    for(int i = 1; i < 7; ++i){
        std::vector<long>aux = ema.Pacientes(std::to_string(i));
        std::cout <<"Medioco : "<<i<<"\n";
        for(const long &x : aux){
            std::cout<<"DNI: "<<x<<"\n";
        }
    }
    return 0;
}
