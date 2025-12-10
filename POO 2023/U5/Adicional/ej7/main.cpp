#include <cctype>
#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>

using std::cout; using std::cin;
using std::end; using std::vector;

int main (int argc, char *argv[])
{
    std::string ruta = "./text.txt";

    std::ifstream arch1(ruta);
    
    std::vector<std::string>v;
    
    std::string palabra;
    
    while(std::getline(arch1, palabra)) v.push_back(palabra);
    
    arch1.close();
    
    for (size_t i = 0; i < v.size(); i++) {
    
        std::string minuscula = v[i];

        for (size_t e = 0; e < minuscula.size(); ++e) {
        
            minuscula[e] = tolower(minuscula[e]);
        }

        v[i] = minuscula;
    }

    std::ofstream arch2(ruta, std::ios::trunc);

    for (std::string letra : v) {
    
        arch2 << letra<<"\n";
    }

    arch2.close();


    std::ifstream arch3(ruta);

    std::vector<std::string>v2;

    while(std::getline(arch3,palabra)) v2.push_back(palabra);

    arch3.close();

    char punto = '.';
    
    char punto_coma = ';';

    for(size_t e = 0 ;e < v2.size(); ++e){
        
        std::string letra = v[e];
        
        for(size_t i = 0; i < letra.size(); ++i){

            switch (i) {
                case 0:
                    letra[i] = toupper(letra[i]);
        
                    v2[e] = letra;
                    
                    break;
    
                default:
                    
                    if(letra[i] == punto) letra[i+2] = toupper(letra[i+2]);

                    if(letra[i] == punto_coma) letra[i+2] = toupper(letra[i+2]);
            }

            v2[e] = letra;
        }
    }

    std::ofstream arch4("./nuevo.txt");

    for(std::string letra : v2) arch4 << letra<<"\n";

    arch4.close();

    return 0;
}
