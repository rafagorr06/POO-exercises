#include "RecursosHumanos.h"

bool RecursosHumanos::Eliminar(std::string e){
    int contador = 0;
    for(Persona i : p){
        std::string nom = i.nombre;
        for(size_t j = 0; j < nom.size();++j){
            if(nom.substr(j,e.size()) == e){
                std::swap(p[contador], p[p.size()-1]);
                p.pop_back();
                return true;
            }
        }
        ++contador;
    }
    return false;
}

bool RecursosHumanos::Leer(std::string n){

    std::ifstream arch1("./emanuel.bin",std::ios::binary|std::ios::in|std::ios::ate);
    char nombre[256];
    int tamanio = arch1.tellg() / (sizeof(nombre)+3*sizeof(int));

    p.clear();
    int dia,mes,anio;
    Persona aux;

    arch1.seekg(0);
    for(size_t i = 0; i < tamanio; ++i){
        arch1.read(nombre, sizeof(nombre));
        arch1.read(reinterpret_cast<char*>(&dia), sizeof(int));
        arch1.read(reinterpret_cast<char*>(&mes), sizeof(int));
        arch1.read(reinterpret_cast<char*>(&anio), sizeof(int));
        std::string nom(nombre);
        aux.nombre = nom;
        aux.dia = dia;
        aux.mes = mes;
        aux.anio = anio;
        p.push_back(aux);
    }
   
    arch1.close();
    return true;
}
bool RecursosHumanos::CargarPersonas(Persona a){
    int tamanio = p.size();
    p.push_back(a);
    if(tamanio < p.size()) return true;
    else return false;
}

bool RecursosHumanos::Guardar(std::string n){

    std::ofstream arch1(n,std::ios::binary|std::ios::out);
    
    if(!arch1.is_open())return false;

    for(int i = 0; i < p.size();++i){
        char nombre[256]; 
        strcpy(nombre,p[i].nombre.c_str());
        int dia = p[i].dia;
        int mes = p[i].mes;
        int anio = p[i].anio;
        arch1.write(nombre, sizeof(nombre));
        arch1.write(reinterpret_cast<char*>(&dia),sizeof(int));
        arch1.write(reinterpret_cast<char*>(&mes),sizeof(int));
        arch1.write(reinterpret_cast<char*>(&anio),sizeof(int));
    }
    arch1.close();
    return true;

}
