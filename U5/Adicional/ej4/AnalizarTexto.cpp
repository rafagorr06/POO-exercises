#include "AnalizarTexto.h"
#include <cctype>
#include <fstream>
#include <string>

AnalizaTexto::AnalizaTexto(std::string r):ruta(r){}

int AnalizaTexto::CantidadCaracteres(){
    
    std::ifstream arch(ruta);
    
    std::string palabra;
    
    int contador = 0;
    
    while(arch >> palabra) contador += palabra.length();
    
    arch.close();
    
    return contador;
}

int AnalizaTexto::CantidadParrafos(){

    std::ifstream arch(ruta);

    std::string palabra;

    int contador = 0;

    while(std::getline(arch, palabra)) ++contador;

    arch.close();

    return contador;
}

int AnalizaTexto::CantidadLetras(){

    std::ifstream arch(ruta);

    std::string palabra;

    int contador = 0;


    while(arch >> palabra){

        for(char i : palabra){

            if(std::isalpha(i)) ++contador;
        
        }

    }

    arch.close();

    return contador;
}

int AnalizaTexto::CantidadEspacios(){

    std::ifstream arch(ruta);

    std::string palabra;

    char esp = ' ';

    int contador = 0;

    while(std::getline(arch,palabra)){
        
        for(char i : palabra){

            if(i == esp) ++contador;
        }
    }

    arch.close();

    return contador;
}

int AnalizaTexto::CantidadEspeciales(){

    std::ifstream arch(ruta);

    std::string palabra;

    int contador = 0;

    while(arch >> palabra){

        for(char i : palabra){

            if(!std::isalpha(i) and !std::isdigit(i)){

                ++contador;
            }
        }
    }

    arch.close();

    return contador;
}
