#include "AnalizarTexto.h"

int main (){

    std::string ruta = "./text.txt";

    AnalizaTexto ema(ruta);
    
    std::cout <<"Cantidad Caracteres: "<<ema.CantidadCaracteres()<<"\n";
    
    std::cout <<"Cantidad Parrafor: "<<ema.CantidadParrafos()<<"\n";
    
    std::cout <<"Cantidad Letras: "<<ema.CantidadLetras()<<"\n";
    
    std::cout <<"Cantidad Espacios: "<<ema.CantidadEspacios()<<"\n";
    
    std::cout <<"Cantidad Especiales: "<<ema.CantidadEspeciales()<<"\n";

    return 0;
}
