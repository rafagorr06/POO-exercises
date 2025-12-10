#ifndef CLINICA_H
#define CLINICA_H
#include <string>
#include <map>
#include <vector>
#include <algorithm>
class Clinica{
    private:
        std::map<std::string,std::vector<long>>clinica;
    public:
        Clinica();
        bool AgregarPaciente(std::string, long);
        std::vector<long> Pacientes(std::string);
        bool Eliminar(long);
};

#endif /* 
structt
class Clinica{

}; */
