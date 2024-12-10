///Escriba un programa que cargue en un vector de strings una lista de palabras
///desde un archivo de texto (que contendrá una palabra por línea), muestre en
///pantalla la cantidad de palabras leídas, las ordene en el vector alfabéticamente, y
///reescriba el archivo original con la lista ordenada.
///Ayuda: para ordenar un vector v de principio a fin puede utilizar la sentencia “sort(v.begin(),v.end());”

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream archi_i("palabras.txt"); 			///Abro el archivo para leer
	if(!archi_i.is_open()){	          			///Compruebo si abrio correctamente
		cerr<<"No se pudo abrir el archivo";
		return 1;
	}
	
	vector<string>listaP;						///Donde guardo las palabras
	string unaP;								///Que tiene que leer(string)
	
	while(archi_i>>unaP){						///Mientras archi_i lea un string sigue
		listaP.push_back(unaP);
	}
	archi_i.close();
	
	cout<<"Lista sin orden:"<<endl;
	for(auto x : listaP){
		cout<<x<<endl;
	}
	cout<<endl;
	
	sort(listaP.begin(),listaP.end());			///Ordena el vector alfabeticamente
	
	cout<<"Lista con orden:"<<endl;
	for(auto x : listaP){
		cout<<x<<endl;
	}
	
	ofstream archi_o("palabras.txt"); 			///Abro el archivo para escribir
	for(auto x : listaP){
		archi_o<<x<<endl;						///Escribo por linea
	}
	
	return 0;
}

