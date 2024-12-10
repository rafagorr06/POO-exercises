#include <iostream>
#include <fstream>
#include <map>
#include <vector> 

typedef struct{

    float x;
    char y;

}Datos;

int main (){

    std::ifstream arch1("humedad",std::ios::binary|std::ios::in);
    
    std::ifstream arch2("precipitaciones",std::ios::binary|std::ios::in);
    
    std::ifstream arch3("temperatura",std::ios::binary|std::ios::in);

    std::map<int,std::vector<Datos>>info;

    int fecha;
    
    Datos aux1;
    
    while(arch1.read(reinterpret_cast<char*>(&fecha),sizeof(int)) and 
        arch1.read(reinterpret_cast<char*>(&aux1.x),sizeof(float))){

        aux1.y = 'H';
    
        info[fecha].push_back(aux1);
    
    }

    Datos aux2;
    
    while(arch2.read(reinterpret_cast<char*>(&fecha),sizeof(int)) and 
        arch1.read(reinterpret_cast<char*>(&aux2.x),sizeof(float))){

        aux2.y = 'P';
        
        info[fecha].push_back(aux2);
        
    }

    Datos aux3;
    
    while(arch1.read(reinterpret_cast<char*>(&fecha),sizeof(int)) and 
        arch1.read(reinterpret_cast<char*>(&aux3.x),sizeof(float))){
   
        aux3.y = 'T';    
        
        info[fecha].push_back(aux3);
        
    }

    arch1.close();
    
    arch2.close();
    
    arch3.close();

    int mayor1 = aux1.x, mayor2 = aux2.x, mayor3 = aux3.x;
    
    int minimo1 = aux1.x, minimo2 = aux2.x, minimo3 = aux3.x;
    
    int promedio1 = 0, promedio2 = 0, promedio3 = 0;

    int cant_d1 = 0, cant_d2 = 0, cant_d3 = 0;

    for(auto & [x , y] : info){

        for(size_t i = 0; i < y.size(); ++i){
        
            switch (y[i].y){
            
                case 'H': 
                    
                    if(mayor1 < y[i].x) mayor1 = y[i].x;
                    if(minimo1 > y[i].x) minimo1 = y[i].x;
                    promedio1 += y[i].x;
                    ++cant_d1;
                    break;

                case 'P': 
                    
                    if(mayor1 < y[i].x) mayor1 = y[i].x;
                    if(minimo1 > y[i].x) minimo1 = y[i].x;
                    promedio1 += y[i].x;
                    ++cant_d1;
                    break;

                case 'T':

                    if(mayor1 < y[i].x) mayor1 = y[i].x;
                    if(minimo1 > y[i].x) minimo1 = y[i].x;
                    promedio1 += y[i].x;
                    ++cant_d1;
                    break;
            }
        }
    }
    
    std::ofstream archx ("resumen.txt",std::ios::out);

    archx << "H,"<<mayor1<<","<<minimo1<<","<<promedio1/cant_d1<<"\n";
    
    archx << "P,"<<mayor2<<","<<minimo2<<","<<promedio2/cant_d2<<"\n";
    
    archx << "T,"<<mayor3<<","<<minimo3<<","<<promedio3/cant_d3<<"\n";

    return 0;
}


