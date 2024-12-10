///Se tiene un archivo “inscriptos.txt” con una lista de nombres de alumnos inscriptos
///al cursado de Fundamentos de Programación. Se desea distribuir los estudiantes	
///en comisiones de práctica de no más de 30 alumnos. Escriba un programa que
///determine cuantas comisiones deberían formarse de acuerdo a la cantidad de
///inscriptos y reparta los alumnos en comisiones de igual tamaño, guardando la lista
///de alumnos de cada comisión en archivo de texto “comision1.txt”, “comision2.txt”, …“comisionN.txt”.
///Ayuda: puede utilizar la clase stringstream como auxiliar para concatenar en un string texto y números para formar los nombres de los archivos.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ifstream archi_C("inscriptos.txt");		///abro archi_C
	if(!archi_C.is_open()){					///esta abierto?
		cerr<<"Archivo no logro abrirse";
		return 1;
	}
	vector<string>Listado;					///Donde guardo los nombres
	string nomape;							///que lee el archi(String)
	
	while(getline(archi_C,nomape)){			///mientras lea el string con espacio
		Listado.push_back(nomape);
	}
	archi_C.close();
	
	int comisiones = (Listado.size()/30);
	cout<<"Usted necesita "<<comisiones<<" comisiones para "<<Listado.size()<<" alumnos"<<endl;
	
	int contador= 0; int index= 1;
	
	for(int i=0;i<Listado.size();i++){
		ofstream archi_Com;
		if(contador<30){
			string r= "comision "+to_string(index)+".txt";  ///creo nombre txt
			if(!archi_Com.is_open()){						///abre?
				archi_Com.open(r,ios::app);
			}
			archi_Com<<Listado[i]<<endl;
			archi_Com.close();
			++contador;
		}
		else{
			contador=1;										///en esta instancia debo hacer todo el proceso por que sino pierdo un Listado[i]
			++index;
			string r= "comision "+to_string(index)+".txt";  ///creo nombre txt
			if(!archi_Com.is_open()){						///abre?
				archi_Com.open(r,ios::app);
			}
			archi_Com<<Listado[i]<<endl;
			archi_Com.close();
		}
	}
	
	return 0;
}

