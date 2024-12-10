/*
Escriba una funci�n que utilice punteros para buscar e informar la direcci�n de un
entero dentro de un arreglo. Se pasan como par�metros el arreglo, su tama�o y el
entero a buscar. Si el dato no se encuentra, devolver la direcci�n de memoria nula
(nullptr o NULL). �Desde un programa cliente, c�mo se obtiene el �ndice del
elemento encontrado cuando la funci�n no devuelve nullptr?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *buscar(int *x,int y,int vb){
	int *z=nullptr;
	for(int i=0;i<y;i++)
		if (*(x+i)==vb){
			z=(x+i);
			break;
		}
	return z;
}


int main() {
	int N,i,valor;
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>N;
	int *pb,*p=new int[N];
	srand(time(0));
	for(i=0;i<N;i++) {
		*(p+i)=rand()%501+1000;
		cout<<i<<":  "<<(p+i)<<":  "<<*(p+i)<<endl;
	}
	
	cout<<"\nIngrese el valor a buscar: ";
	cin>>valor;
	pb=buscar(p,10,valor);
	if(pb!=nullptr){
		cout<<"\nEncontrado en direcci�n: "<<pb<<endl;
		cout<<"Indice: "<<pb-p<<endl;
	} else
		cout<<"\nValor no encontrado";
	
	delete[]p;
	return 0;
}

