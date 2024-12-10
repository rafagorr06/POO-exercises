///En un archivo de texto llamado lista.txt, como el que se muestra a la derecha, se encuentran los nombres y notas
///de los alumnos de una comisión de Programación Orientada a Objetos.
///a) Escriba una función modificar que reciba el nombre de un alumno y dos notas, y modifique el archivo
///reemplazando las dos notas de ese alumno.
///b) Escriba una función que lea la lista del archivo y genere otro archivo de texto
///promedios.txt con una tabla donde cada línea posea el nombre, el promedio,
///y la condición final de cada uno de los alumnos.
///Ayuda: utilice manipuladores de flujo (setw, right, left, fixed, setprecision) para dar
///formato a la tabla del archivo que se genera en b).

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Alumno{ string nombre; int nota1, nota2;};

void Modificar(vector<Alumno>&List, string n_b, int n1b, int n2b){  ///A
	for(int i=0;i<List.size();++i){
		if(List[i].nombre == n_b){
			List[i].nota1 = n1b;
			List[i].nota2 = n2b;
		}
	}
	ofstream archi_O("lista.txt"); ///Editar archivo
	for(int i=0;i<List.size();++i){
		archi_O<<List[i].nombre<<endl;
		archi_O<<List[i].nota1<<" "<<List[i].nota2<<endl;
	}
	archi_O.close();
}

void promedio(vector<Alumno>&List){
	ofstream archiNEW("promedios.txt");
	float prom;
	for(int i=0;i<List.size();++i){
		archiNEW<<List[i].nombre<<endl;
		prom=((List[i].nota1+List[i].nota2)/2);
		archiNEW<<prom<<endl;
		if(prom >= 70.0){
			archiNEW<<"Promocion"<<endl;
		}
		else if(prom >= 40.0 and prom < 70.0){
		   archiNEW<<"Regular"<<endl;
		}
		else{
			archiNEW<<"Libre"<<endl;
		}
	}
}

int main() {
	ifstream archi_i("lista.txt");					///Abro
	if(!archi_i.is_open()){
		cerr<<"No se pudo abrir el archivo";
		return 1;
	}
	vector<Alumno>Lista;
	Alumno nuevo;
	
	while(getline(archi_i,nuevo.nombre)){			///Uso getline, por que tiene un espacio el nombre
		archi_i>>nuevo.nota1>>nuevo.nota2;			///Lee las notas
		Lista.push_back(nuevo);
		archi_i.ignore();							///Despues del getline, y leer todo, va ignore
	}
	archi_i.close();
	
	cout<<"Vector original:"<<endl;
	for(auto x : Lista){
		cout<<x.nombre<<endl;
		cout<<x.nota1<<" "<<x.nota2<<endl;
	}
	cout<<endl;
	
	cout<<"Nombre a modificar su nota: ";string no_b;getline(cin,no_b);
	cout<<"Nota 1: ";int n1_b;cin>>n1_b;
	cout<<"Nota 2: ";int n2_b;cin>>n2_b;
	
	Modificar(Lista,no_b,n1_b,n2_b);
	promedio(Lista);
	
	return 0;
}

