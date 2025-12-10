#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct Alumno {
	string nombre;
	int nota1, nota2;
};

void Modificar (string alumno, int nota1, int nota2){
	ifstream archivo("lista.txt");
	vector<Alumno>v; string s; int n1, n2;
	Alumno aux;
	if(!archivo.is_open()) throw runtime_error("Error");
	while (getline(archivo,s) && archi>>nombre>>n1>>n2){
		aux.nombre=s;
		aux.nota1=n1;
		aux.nota2=n2;
		v.push_back(aux);
		archi.ignore();
	}
}

int main() {
	
	return 0;
}

