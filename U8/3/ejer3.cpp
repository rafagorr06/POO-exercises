///Cree un programa que lea valores flotantes por teclado y los inserte en una lista. Luego:
///a. Muestre dicha lista.
///b. Inserte en medio de cada par de elementos contiguos el promedio de
///dichos elementos y guarde la lista resultante en un archivo de texto llamado “listafloat.txt”.
///c. Responda: ¿es posible ordenar solamente una porción de la lista de la
///misma manera que se hizo con el vector en el ejercicio 8.2?

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main() {
	list<float>L;
	cout<<"Valor nuevo (-1 termina): ";float x;cin>>x;
	while (x != -1){
		L.push_back(x);
		cout<<"Valor nuevo (-1 termina): ";cin>>x;
	}
	cout<<endl<<endl;
	
	///A
	cout<<"Su lista es"<<endl;
	for(float x : L){
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	
	///B
	for(auto it= L.begin(); it!= prev(L.end()); advance(it,1)){
		int prom= (*next(it)+*it)/2;
		it= L.insert(next(it),prom);
	}
	cout<<endl<< endl;
	
	cout<<"Su nueva lista es"<<endl;
	for(float x : L){
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	
	
	ofstream archi ("Lista.txt");
	for(auto it= L.begin(); it!= L.end(); ++it){
		archi<<*it<< " ";
	}
	archi.close();
	
	return 0;
}

