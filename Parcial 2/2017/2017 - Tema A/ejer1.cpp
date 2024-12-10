///Escriba una función genérica para cualquier tipo de elemento llamada 
///vector_a_lista(...) que reciba un std::vector y retorne una std::list que contenga los elementos del vector
///de entrada, sin repetidos. Debe mantener el orden del vector. 
///Escriba un programa cliente que genere un vector con 40 enteros aleatorios, utilice 
///la función para pasarlos a una lista, y muestre la lista en pantalla.
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
list<T>lista_a_vector(vector<T>&v){
	list<T>aux;
	for(auto it=v.begin();it!=v.end();++it){
		auto it2=remove(next(it),v.end(),*it);
		v.erase(it2,v.end());
	}
	for(T x:v){
		aux.push_back(x);
	}
	return aux;
}
int main() {
		vector<int>v;
		for(int i=0;i<15;++i){	///genera vector
			v.push_back(1+rand()%8);
		    cout<<v[i]<<endl;
		}
		cout<<endl;
		
		list<int>lista=lista_a_vector(v);
		for(int b:lista){
			cout<<b<<endl;
		}
		
		return 0;
}
