///Parcial 1 2020 - Ej 1
///a) Diseñe una función C++ superaprom(..) que tenga como parámetros la dirección de un
///arreglo de flotantes(puntero), y su longitud. La función debe devolver la cantidad de elementos del
///arreglo que superan el promedio de sus elementos.

///b) Luego escriba un programa C++ que ingrese la cantidad de datos flotantes a ingresar,
///defina un arreglo dinámico de flotantes e ingrese los datos del arreglo.

///c) El programa debe invocar a la función superaprom(...) para obtener cuantos datos
///superan el promedio de los datos ingresados y después definir un nuevo arreglo dinámico
///que solo contenga los datos que superan al promedio. Mostrar el arreglo que tiene
///datos mayores al promedio.
///NOTAS: No usar la clase vector: Usar solo notación de punteros (no usar operador [ ]).

#include <iostream>
using namespace std;

float promedio(const float *v, int L) {
	float p = 0;
	for (int i=0; i<L; ++i) {
		p += *(v+i); // v[i];
	}
	return p/L;
}

int contar(const float *v, int L, float prom) {
	int c = 0;
	for (int i=0; i<L; ++i) {
		if (*(v+i)>prom) {
			++c;
		}
	}
	return c;
}

int superaProm(const float *v, int L) {			///a
	float prom = promedio(v,L);
	return contar(v,L,prom);
}

int main() {

	cout<<"Longitud: ";int L1;cin >> L1;

	float *v1 = new float[L1];	///Arreglo dinamico (puntero)
	for (int i=0; i<L1; ++i) { 
		cout<<"Valor: ";cin>>*(v1+i);	///Ingreso el valor
	}
	
	int L2 = superaProm(v1,L1);	///La segunda longitud tendra el tamaño de los valores que superen al promedio
	
	float prom = promedio(v1,L1);
	cout<<"Promedio: "<<prom<<endl;
	cout<<endl;
	
	float *v2 = new float[L2];
	int j=0;
	for (int i=0; i<L1; ++i) {	///Armo el vector dinamico copiando los valores que superan el promedio
		if (*(v1+i)>prom) {
			*(v2+j) = *(v1+i);	///Si es mayor al promedio, guardo el valor en el nuevo vector y aumento J
			++j;
		}
	}
	
	cout<<"Valores que superan el promedio:"<<endl;
	cout<<endl;
	
	for (int i=0; i<L2; ++i) { 
		cout<<*(v2+i)<<" ";
	}
	
	delete [] v2;
	delete [] v1;
	return 0;
}

