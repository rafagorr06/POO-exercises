///Escriba un programa que permita al usuario ingresar 15 valores por teclado, los
///almacene en un vector y luego:
///a. Muestre el vector generado utilizando 3 mecanismos de iteración diferentes.
///1. utilizando el operador []
///2. utilizando iteradores
///3. utilizando el for basado en rangos
///4. ¿en qué caso es conveniente utilizar cada mecanismo?
///b. Calcule y muestre
///1. los valores de los elementos máximo y mínimo
///2. la suma de todos los elementos del arreglo
///3. el promedio y la mediana de los elementos del arreglo
///c. Permita al usuario ingresar un valor, e informe si se encuentra en el vector,
///y en caso afirmativo, en qué posición.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	int valor;
	vector<int>v;
	for(int i=0;i<15;i++){ 
		valor = rand()%100;
		v.push_back(valor); ///Carga de valores
	}
	
	///A
	for(int i=0;i<15;i++){
		cout<<v[i]<<" "; ///Punto 1
	}
	cout<<endl<<endl;
	for(auto it=v.begin(); it!=v.end();it++){ ///auto=vector<int>::iterator
		cout<<*it<<" "; ///Punto 2, funciona como un puntero
	}
	cout<<endl<<endl;
	for(int x:v){ ///Para modificar uso (int &x:v)
		cout<<x<<" "; ///Punto 3
	}
	cout<<endl<<endl;
	
	///B
	auto itmax= max_element(v.begin(),v.end());
	cout<<"Max: "<<*itmax<<", con pos "<<distance(v.begin(),itmax)<<endl; ///Punto 1
	
	auto itmin= min_element(v.begin(),v.end());
	cout<<"Min: "<<*itmin<<", con pos "<<distance(v.begin(),itmin)<<endl; ///Punto 1
	
	auto acu = accumulate(v.begin(),v.end(),0);
	cout<<"Suma total: "<<acu<<endl; ///Punto 2
	
	float prom=(acu/15.0);
	cout<<"El promedio es "<<prom<<endl;

	///C
	cout<<endl;
	cout<<"Valor a buscar: ";int valorB;cin>>valorB;
	auto itb= v.begin();///pos 0
	for(auto it=v.begin(); it!=v.end();it++){
		if(*it==valorB){ ///si el puntero it coincide con el buscado
			itb=it; ///el itb toma la pos de donde esta el buscado
		}
	}
	cout<<"El valor esta en la pos: "<<(itb-v.begin())<<endl;
	
	sort(v.begin(),v.end());
	int m=(v.size()/2);
	auto itm= v.begin();
	advance(itm,m);
	cout<<"La media es de: "<<*itm;
	cout<<endl;
	
	return 0;
}

