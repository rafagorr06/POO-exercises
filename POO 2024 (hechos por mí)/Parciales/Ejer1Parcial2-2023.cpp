#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<string> CargarDatos (string nombrearchi) {
	ifstream archi(nombrearchi);
	vector<string>lista;
	string linea;
	while(getline(archi,linea)) {
		lista.push_back(linea);
	}
	archi.close();
	return lista;
}

void EliminarDupli (vector<string>&lista){
	sort(lista.begin(), lista.end());
	unique(lista.begin(),lista.end());
}

string GenerarEmail (string &nombrecompleto){
	size_t espacio = nombrecompleto.find(' ');
	string nombreletra = nombrecompleto.substr(0,1);
	string apellido = nombrecompleto.substr(espacio+1);
	string email = nombreletra+apellido+"@fich.unl.edu.ar";
	return email;
}
	
void  GenerarComisiones (vector<string>&lista) {
	int alumnoscomision= 60;
	
	for(int i=0;i<5;i++) { 
		string nombrearchivo = "comision"+to_string(i+1);
		ofstream archivo(nombrearchivo);
		int inicio = i*alumnoscomision;
		int fin = min(static_cast<int>(lista.size()),inicio+alumnoscomision);
		for(int j=inicio;j<fin;j++) { 
			size_t espacio = lista[j].find(' ');
			string nombre = lista[j].substr(0,espacio);
			string apellido = lista[j].substr(espacio+1);
			string email = GenerarEmail(lista[j]);
			
			archivo << apellido << "," << nombre << "," << email << endl;
		}
		
		archivo.close();
	};
	
	
}

int main() {
	
	return 0;
}

