///Escriba a través de un programa C++ un archivo binario llamado grupo.dat, formado
///por un conjunto de 200 pares de números generados aleatoriamente. Cada par de
///datos se conforma por un entero y un flotante.	

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Par{int ent; float flot;};

int main() {
	ofstream archi_o("grupo.dat",ios::binary);	///abro el archivo para lectura y binario
	
	Par valor;									///creacion de par, donde cada for agrega a archi_o
	for(int i=0;i<200;i++){						///no se puede usar contenedor en binario
		valor.ent= rand();
		valor.flot= rand()/100.0;
		archi_o.write(reinterpret_cast<char*>(&valor),sizeof(valor));
	}
	archi_o.close();
	
	return 0;
}

