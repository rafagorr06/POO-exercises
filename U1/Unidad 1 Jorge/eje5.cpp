/*
Ejercicio 5
Utilizando notaci�n de punteros, generar un arreglo din�mico y lineal de N
elementos num�ricos enteros, con valores aleatorios entre 1000 y 1500, y muestre
en pantalla la direcci�n de memoria del mayor elemento. N es un dato ingresado
por el usuario.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int N,i,mayor=0;
	int *pmay;
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>N;
	int *p=new int[N];
	srand(time(0));
	for(i=0;i<N;i++) {
		*(p+i)=rand()%501+1000;
		cout<<i<<":  "<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	for(i=0;i<N;i++) {
		if(*(p+i)>mayor){
			mayor = *(p+i);
			pmay =  p+i;
		}
	}
	
	cout<<"\nLa direccion del mayor elemento es: "<<pmay<<"  su posici�n es: "<<pmay-p<<endl;
	delete []p;
	return 0;
}

