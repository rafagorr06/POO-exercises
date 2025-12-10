#ifndef RECURSOS_HUMANOS_H
#define RECURSOS_HUMANOS_H
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
typedef struct {

    std::string nombre;
    int dia,mes,anio;

} Persona;

class RecursosHumanos{

    private:

        std::vector <Persona> p;

    public:
        bool CargarPersonas(Persona);
        int VerTamanio(){return p.size();}
        std::string VerNombre(int i)const{return p[i].nombre;}
        bool Guardar(std::string);
        bool Leer(std::string);
        bool Eliminar(std::string);
};

#endif
