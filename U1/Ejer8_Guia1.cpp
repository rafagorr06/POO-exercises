/*
Ejercicio 8
Analice el c�digo C++ del recuadro de abajo para responder lo siguiente:
a. �Qu� tipo de par�metros actuales se emplean para llamar a func()?.
b. �Qu� tipos de par�metros formales se definen en func()?.
c. �Qu� tipo de informaci�n devuelve la funci�n func()?.
d. �Cu�l es la salida que se obtiene en el programa propuesto?
*/
#include <iostream>
using namespace std;
void func (int *s, int *e, int *sum){
	(*sum)=0;
	for(int*p=s; p<e;p++)
		(*sum)+=*p;
}
int main() {
	int x[6]={12,34,56,67,39,90};
	int suma;
	func(x,x+6,&suma);
	cout<<suma<<endl;
	return 0;
}

/*
a) el nombre del arreglo al primero y la direccion del siguiente del ultimo del arreglo, y la direccion de la variable suma
b) 3 punteros a enteros
c) el puntero a una posici�n de memoria entera 
d) la suma de los elementos de un arreglo


*/
