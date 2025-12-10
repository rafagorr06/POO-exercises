#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main (int argc, char *argv[])
{
    //std::system("wget -O text.txt http://www.gutenberg.org/files/2000/old/2donq10.txt");

    std::ifstream arch1("./text.txt");

    std::string buscar, palabra;

    std::cout << "Buscar: ";

    std::getline(std::cin,buscar);

    int contador = 0;

     for(size_t e = 0; e < buscar.size();++e){
            
         buscar[e] = tolower(buscar[e]);
         
     }

     while(std::getline(arch1,palabra)){

        for(size_t i = 0; i < palabra.size();++i) palabra[i] = tolower(palabra[i]);

        for(size_t i = 0;  i < palabra.size();++i){

            if(palabra.substr(i, buscar.size()) == buscar) ++contador;
        }
    }

    std::cout <<contador<<"\n";

    return 0;
}

