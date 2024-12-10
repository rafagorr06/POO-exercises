#include <ctime>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main (){

    std::ifstream arch1("./text.txt",std::ios::in);

    std::string aux, nom , ape ;

    std::map<std::string,std::vector<std::string>>inscriptos;

    while(std::getline(arch1, aux)){

        for(size_t i = 0 ; i < aux.size(); ++i){
            
            if(aux[i] == ','){

                std::stringstream ss(aux);

                std::getline(ss, ape, ',');
                
                std::getline(ss, nom);

                std::vector<std::string>::iterator it = std::find(inscriptos[ape].begin(), inscriptos[ape].end(), nom);

                if(it == inscriptos[ape].end())
                
                    inscriptos[ape].push_back(nom);

                break;
            }

            if(aux[i] == ' '){

                std::stringstream ss(aux);

                std::getline(ss, ape, ' ');
                
                std::getline(ss, nom);

                std::vector<std::string>::iterator it = std::find(inscriptos[ape].begin(), inscriptos[ape].end(), nom);

                if(it == inscriptos[ape].end())
                
                    inscriptos[ape].push_back(nom);

                break;

            }
        }
    }

    arch1.close();

    std::ofstream arch2 ("./text2.txt",std::ios::out);

    int lineas = 0;
    
    for(auto &[apellido, v_nombre] : inscriptos){
    
        for(const std::string nombre : v_nombre ){
        
            ++lineas;
            
            arch2 <<lineas<<","<<apellido<<","<<nombre<<"\n";

        }
    }

    return 0;
}
