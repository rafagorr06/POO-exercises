#include <iostream>
#include <fstream>
using std::cout; using std::cin; using std::endl; using std::string;
using std::ofstream; using std::ifstream; using std::fstream;
using std::ios;
void CreateDummyFile(std::string, int);

void VerBinario(std::string);

int main (int argc, char *argv[])
{
    string nombre;
    
    int numero;

    cout <<"Nombre del Archivo: ";cin>>nombre;
    cout <<"Tamaño del Archivo: ";cin>>numero;

    CreateDummyFile(nombre,numero);

    VerBinario(nombre);

    return 0;
}

void CreateDummyFile(string r, int n){

    srand(time(0));

    int elementos = n / sizeof(int);

    ofstream arch1(r,ios::binary);

    int num = rand() % (99-10) + 10;

    for(int i = 0; i < elementos; ++i){

        arch1.write(reinterpret_cast<char*>(&num),sizeof(int));

        num = rand() % (99-10) +10;
    }

    arch1.close();
}

void VerBinario(string r){

    ifstream arch1(r,ios::binary|ios::in);

    int i;

    while(arch1.read(reinterpret_cast<char*>(&i),sizeof(int)))
        cout<<"[*] "<<i<<"\n";
    arch1.close();
}
