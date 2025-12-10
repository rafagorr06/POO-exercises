#include <iostream>
#include <fstream>
using namespace std;

struct par { int entero; float flotante; };

int main() {
	
	ifstream f("grupo.dat", ios::binary|ios::ate);
	if (not f.is_open()) throw runtime_error("No se pudo abrir el archivo");
	f.seekg(0,ios::end);
	int tam_bytes = f.tellg();
	int cant_pares = tam_bytes/sizeof(par);
	par aux;
	f.seekg(0);
	for(int i=0;i<cant_pares;i++) { 
		f.read((char*)&aux,sizeof(aux));
		cout<<aux.entero<<" "<<aux.flotante<<endl;
	}
	return 0;
}

