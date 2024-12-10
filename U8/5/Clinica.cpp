#include "Clinica.h"
#include <vector>

Clinica::Clinica(){
    clinica["1"];
    clinica["2"];
    clinica["3"];
    clinica["4"];
    clinica["5"];
    clinica["6"];
}

bool Clinica::AgregarPaciente(std::string m,long i){
    std::map<std::string,std::vector<long>>::iterator it = clinica.find(m);
    if(it != clinica.end()){
        clinica[m].push_back(i);
        return true;
    }
    else{
        return false;
    }
}

std::vector<long> Clinica::Pacientes(std::string m){
    
    std::map<std::string,std::vector<long>>::iterator it = clinica.find(m);
    
    std::vector<long>error;

    if(it != clinica.end()){
        return clinica[m];
    }
    else return error;
}

bool Clinica::Eliminar(long d){
    
    for(auto it = clinica.begin(); it != clinica.end(); ++it){
        
        auto esta = std::find(it->second.begin(), it -> second.end(), d);
        
        if(esta != it -> second.end()){it -> second.erase(esta);
        
            return true;
        }
    }
    return false;
}
