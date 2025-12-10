#include <iostream>
using namespace std;


//Escriba una función que utilice punteros para buscar y retornar la dirección de un entero dentro de un arreglo. Se
//pasan como parámetros el arreglo, su tamaño y el entero a buscar. Si el dato no se encuentra, debe retornar
//la dirección de memoria nula (nullptr). ¿Desde un programa cliente, cómo se obtiene el índice del elemento
//encontrado cuando la función no devuelve nullptr?

int *buscardireccion (int *p, int n, int entero) {
	for(int i=0;i<n;i++) { 
		if (*(p+i)==entero){
			return p+i;
		} else {
			
		}
	}
	
	return nullptr;
}

int main() {
	int n;
	cout << "Ingrese el tamaño del arreglo"<<endl;
	cin >> n;
	int *p = new int [n];
	
	for(int i=0;i<n;i++) { 
		*(p+i)=rand()%11;
	}
	
	int entero;
	cout << "Ingrese el numero a buscar"<<endl;
	cin >> entero;
	
	int* aux = buscardireccion(p, n, entero);
		
	if (aux != nullptr) {
		cout << aux << endl;
	}

	
	return 0;
}

