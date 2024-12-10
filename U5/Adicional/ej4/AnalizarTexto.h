#ifndef ANALIZA_TEXTO_H
#define ANALIZA_TEXTO_H
#include <string>
#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <vector>
class AnalizaTexto{

    private:
        std::string ruta;
    public:
        AnalizaTexto(std::string);
        int CantidadCaracteres();
        int CantidadParrafos();
        int CantidadLetras();
        int CantidadEspacios();
        int CantidadEspeciales();
};
#endif
