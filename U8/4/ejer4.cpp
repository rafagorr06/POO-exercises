///Declare un arreglo estático de 20 elementos enteros (int v[20];) y luego:
///a. Implemente una función int rand10() que genere un entero aleatorio entre
///-10 y 10, y utilícela como argumento para generate para inicializar el arreglo con valores aleatorios.
///b. Implemente una función bool es_par(int x) que retorne true si el entero que
///recibe es par; y utilícela en combinación con count_if para contar cuantos
///elementos pares hay en el contenedor generado.
///c. Implemente una función bool menor_abs(int a, int b) que reciba dos enteros
///y retorne verdadero cuando el valor absoluto del primero sea menor que el
///valor absoluto del segundo; y utilice esta función en como argumento de
///sort para ordenar el vector por valor absoluto.
///d. Elimine los elementos repetidos utilizando los algoritmos genéricos de la
///STL, y luego muestre el arreglo resultante.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

///A
int rand_10(){ ///generador de valores para la funcion generate
	int x = rand()%21-10;
	return x;
}
	
bool es_par(int x) {
	if( x % 2 == 0){
		return true;
	}else{
		return false;
	}
}
	
bool menor_abs(int a, int b){
	if (abs(a) > abs(b)){
		return true;
	}else{
		return false;
	}
}
	
void positivo( vector<int> &v){
	for(size_t i = 0; i < v.size(); i++){
		int num = v[i];
		if( num < 0 ) {
			num = num * -1;
			v[i] = num;
		}
	}
}


int main() {
	vector<int> v(20);
	
	///A
	generate(v.begin(),v.end(),rand_10);
	
	cout<<"Vector A"<<endl;
	for(auto it= v.begin(); it!= v.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl<<endl;
	
	///B
	int pares= count_if(v.begin(),v.end(),es_par); ///el contador cuenta los pares nomas
	
	cout<<"Hay "<<pares<<" de numeros pares"; 
	cout<<endl<<endl;
	
	///C
	sort(v.begin(),v.end(),menor_abs);

	cout<<"Vector C"<<endl;
	for(auto it= v.begin(); it!= v.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl<<endl;
	
	///D
	unique(v.begin(),v.end());
	cout<<"Vector D"<<endl;
	for(auto it= v.begin(); it!= v.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl<<endl;
	
	positivo(v);
	
	for(size_t i=0; i<v.size(); i++){
		cout<<v[i]<< " ";
	}

	cout<<endl<<endl;
	
	sort(v.begin(),v.end()); 
	
	for(auto it= v.begin(); it!= v.end(); ++it){
		cout<<*it<< " ";
	}
	cout<<endl<<endl;
	
	auto it= unique(v.begin(),v.end());
	
	v.erase(it, v.end());
	reverse(v.begin(),v.end());
	
	for(auto it= v.begin(); it!= v.end(); ++it){
		cout<<*it << " ";
	}
	
	return 0;
}
