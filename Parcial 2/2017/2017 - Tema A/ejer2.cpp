///Se dispone de un archivo de textos USUARIOS.TXT donde cada l�nea contiene el 
///c�digo, sector, el apellido y el nombre . El c�digo es un n�mero entero y el sector es una sola palabra, y
///cada usuario tiene un solo nombre y apellido separado por un espacio en blanco. Escriba una clase que 
///posea entre sus m�todos: a) la funci�n GeneraPassword(), encargada de crear un password 
///concatenando el sector con la primer letra del nombre y el apellido completo de cada usuario y otra 
///funci�n CreaBinario( ) que genere un archivo binario que contenga los datos referentes al c�digo, 
///nombre, apellido y password generado de cada usuario. Programa los m�todos adicionales que considere necesarios.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct datos{char nom[15],ape[15],pass[15]; int cod;};

class Usuario{
	string ruta;
	string password;
	vector<datos>v;
public:
	Usuario(string r):ruta(r){}
	
	void Genera_Password(){
		ifstream archi_in(ruta);
		datos a;string sec,nom,ape;
		while((archi_in>>a.cod)and(archi_in>>sec)and(archi_in>>nom)and(archi_in>>ape)){
			sec=sec+nom[0];
			strcpy(a.pass,sec.c_str());
			strcpy(a.nom,nom.c_str());
			strcpy(a.ape,ape.c_str());
			v.push_back(a);
		}
	}
		
	void CrearBinario(string r){
		ofstream archi_on(r,ios::binary|ios::in);
		for(size_t i=0;i<v.size();i++) { 
			archi_on.write(reinterpret_cast<char*>(&v[i]),sizeof(v[i]));
			
		}
	}
};
int main() {
	Usuario a("usuarios.txt");
	return 0;
}

