///Escriba un programa que defina un vector dinámico de 30 enteros aleatorios menores que 25. Luego:
///a. Ordene en forma descendente los elementos ubicados entre las posiciones
///10 y 20 inclusive, y muestre el vector.
///b. Inserte en un nuevo vector los elementos que fueron ordenados en el
///apartado anterior, y quítelos del vector original.
///c. Permita ingresar un valor por teclado, y muestre cuántas veces aparece
///dicho valor en el vector.
///d. Elimine todas las ocurrencias del valor ingresado en el punto c, utilizando la
///función remove. Responda: ¿Pueden las funciones globales de la STL
///eliminar realmente los elementos (liberando la memoria de un contenedor)?
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>
using namespace std;

int main() {
	int valor;
	vector<int>v;
	for(int i=0;i<30;i++){
		valor = rand()%25;
		v.push_back(valor); ///Carga de valores
	}
	cout<<"Vector original"<<endl;
	for(int x:v){
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	
	///A
	sort((v.begin()+9),(v.begin()+19)); ///orden vector
	reverse(v.begin(),v.end());	///lo invierte
	cout<<"Vector ordenado de la pos 10 al 20 (descendente)"<<endl;
	for(int x:v){
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	
	///B
	vector<int>v2;
	copy((v.begin()+9),(v.begin()+19),back_inserter(v2));	///copia de a hasta b y lo inserte en v2
	cout<<"Vector extraido"<<endl;
	for(int x:v2){
		cout<<x<<" ";
	}
	cout<<endl<<endl;
	
	///C
	cout<<"Valor a contar: ";int vbuscar;cin>>vbuscar;
	int contador= count(v.begin(),v.end(),vbuscar);
	cout<<"El valor aparece: "<<contador<<" veces"<<endl;
	cout<<endl;
	
	///D
	remove(v.begin(),v.end() ,vbuscar);
	for(int x:v){
		cout<<x<<" ";
	}
	
	return 0;
}

