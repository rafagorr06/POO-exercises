#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
typedef struct{

    int gol1, gol2;

} Datos;

void cargarResultado(std::string, int,std::string, std::string, int, int);

int main (){

    std::string ruta = "./text.txt";
    
    int fecha,gol1,gol2;
    
    std::string equipo1,equipo2;

    cargarResultado(ruta,fecha,equipo1,equipo2,gol1,gol2);

    return 0;
}

void cargarResultado(std::string ruta, int f,std::string e1 ,std::string e2, int g1, int g2){

    std::ifstream arch1(ruta,std::ios::in);
    
    std::map<int,std::map<std::string,std::map<std::string,Datos>>> partidos;

    std::string aux;
    
    int fecha, gol1,gol2;
    
    std::string equipo1, equipo2, dato;

    while(std::getline(arch1, aux)){
        
        std::stringstream ss(aux);
        
        std::getline(ss, dato, ',');

        //recien descubro stoi -> crei que (int) dato era correcto, pero no funciona
        fecha = std::stoi(dato);

        std::getline(ss, equipo1, ',');

        std::getline(ss, dato, ',');

        gol1 = std::stoi(dato);
        
        std::getline(ss, equipo2, ',');
        
        std::getline(ss, dato, ',');
        
        gol2 = std::stoi(dato);
    
        partidos[fecha][equipo1][equipo2];

        auto it1 = partidos.find(fecha);
    
        auto it2 = it1-> second.find(equipo1);
        
        auto it3 = it2 -> second.find(equipo2);
        
        it3->second.gol1 += gol1;
        
        it3->second.gol2 += gol1;
    }

    arch1.close();

    auto it1 = partidos.find(f);

    auto it2 = it1->second.find(e1);

    auto it3 = it2->second.find(e2);

    
    if(it1 != partidos.end() and it2 != it1->second.end() and it3 != it2->second.end()){

        std::ofstream arch2 (ruta, std::ios::out|std::ios::trunc);

        for(auto & [fec , eq1] : partidos)

            for(auto & [eqq1 , eq2] : eq1)

                for(auto &[eqq2 , goles] : eq2)

                    arch2 <<fec<<","<<eqq1<<","<<goles.gol1<<","<<eqq2<<gol2<<"\n";
                   
    }

    else{

        std::ofstream arch2 (ruta,std::ios::in|std::ios::app);
    
        arch2 <<f<<","<<e1<<","<<","<<g1<<","<<e2<<","<<g2<<"\n";
    }

}

