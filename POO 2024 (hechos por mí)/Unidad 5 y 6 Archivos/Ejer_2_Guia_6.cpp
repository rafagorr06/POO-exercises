#include <iostream>
#include <fstream>
using namespace std;

struct par { int entero; float flotante; };

int main() {
	fstream f("grupo.dat", ios::binary | ios::in | ios::out);
	if (not f.is_open()) throw runtime_error("No se pudo abrir el archivo");
	int posicion;
	par aux;
	cin>>posicion>>aux.entero>>aux.flotante;
	f.seekg(posicion*sizeof(par));
	f.write((char*)&aux,sizeof(par));
	return 0;
}

