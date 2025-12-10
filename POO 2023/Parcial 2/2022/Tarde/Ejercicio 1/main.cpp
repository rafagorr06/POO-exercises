#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int main (){

    std::ifstream arch1("./binario.bin",std::ios::binary|std::ios::in);
    
    //un map tiene un key y un dato referente a esa key;

    std::map<int,std::map<char,int>> competencia;

    //este map tiene una key = cod_universidad y su dato referente es otro map
    //que tiene una key = nombre del equipo y puntos.

    int uni, puntos;
    char equipo;

    while(arch1.read(reinterpret_cast<char*>(&uni),sizeof(int)) and 
        
            arch1.read(reinterpret_cast<char*>(&equipo),sizeof(equipo)) and //se pasa la variable no el tipo de dato ver -> [1]
        
        arch1.read(reinterpret_cast<char*>(&puntos),sizeof(int))){
                
        competencia[uni][equipo];

        //busco el codigo de la uni
        auto it1 = competencia.find(uni);

        //busco el equipo
        auto it2 = it1->second.find(equipo);

        //sumo a los puntos del equipo
        it2 -> second = it2->second + puntos;
           
    }
  
    //compatible esta forma de iterar con  >= c++17
    //como un mapa tiene dos valores. la key la guardo en map1 como un INT 
    //El otro map lo guardo dentro de map2
    for(auto & [uni , map2] : competencia){

        int puntos = 0;

        for( auto & [equi, punt] : map2) puntos += punt;

        std::cout <<"La universidad: "<<uni<<" consiguio: "<<puntos<<"\n";

    }

    for(auto & [uni, map2] : competencia){

        int puntos = 0;

        std::string equipo;

        for(auto & [equi, punt] : map2){

            if(punt > puntos) {

                puntos = punt;

                equipo = equi;
            }
        }

        std::cout <<"El mejor equipo de la universidad : "<<uni<<" es: "<<equipo<<"\n";
    }

    return 0;
}
/*
[1] std::cout <<"Cuando ocupa un char: "<<sizeof(char)<<"\n";
    std::cout <<"Cuano pesa equipo: "<<sizeof(equipo)<<"\n";
*/
