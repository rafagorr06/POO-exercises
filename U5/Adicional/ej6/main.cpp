#include <iostream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main (int argc, char *argv[])
{
    std::string buscar, reemplazar, palabra, ruta  =" ./text.txt";

    std::vector<std::string> v;

    std::ifstream arch(ruta);
   
    while(std::getline(arch,palabra)){

        v.push_back(palabra);

    }

    arch.close();

    std::cout <<"Buscar Frase: ";std::getline(std::cin,buscar);
    
    std::cout <<"reemplazar por que frace: ";std::getline(std::cin,reemplazar);
    return 0;
}
