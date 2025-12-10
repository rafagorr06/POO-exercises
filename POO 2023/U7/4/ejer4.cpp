/*U7 EJ 4
Desarrolle una clase templatizada llamada ManejadorArchivo que posea métodos
y atributos para manipular un archivo binario que contenga registros del tipo de
dato especificado por el parámetro. La clase debe poseer métodos para:
a. Abrir un archivo binario y cargar los registros en memoria.
b. Obtener el registro en una posición especificada por el usuario.
c. Modificar el registro en una posición determinada.
d. Actualizar la información del archivo con los cambios.
e. Utilice la clase desde un programa cliente para leer los registros escritos en
el archivo binario generado en el ejercicio 6.5.*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template<typename T> 
class ManejadorArchivo{
	vector<T> v;
	string nomarchi;
public:
	ManejadorArchivo(string na){nomarchi = na;}
	void AbriryCargar(){ //a
		fstream f(nomarchi,ios::binary|ios::in|ios::out|ios::ate);
		int cant= f.tellg()/sizeof(T);
		f.seekg(0);
		for(int i=0;i<cant;i++) { 
			T p;
			f.read((char*)&p,sizeof(p));
			v.push_back(p);
		}
		f.close();
	}
	T &operator[] (int x){ return v[x];} //b y c
	void Actualizar(){ //d
		fstream f(nomarchi,ios::binary|ios::in|ios::out|ios::trunc);
		for(int i=0;i<v.size();i++) {
			f.write((char*)&v[i],sizeof(v[i]));
		}
		f.close();
	}
};

int main() {
	
	return 0;
}







