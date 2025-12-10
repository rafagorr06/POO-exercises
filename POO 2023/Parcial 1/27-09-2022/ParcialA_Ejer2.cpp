#include <iostream>
#include <tuple>
using namespace std;

tuple<int *,int>NuevoArreglo(int *PrincipioArreglo, int *PosicionACambiarArreglo, int *FinalArreglo){
	int NewSize= FinalArreglo - PrincipioArreglo - 1; ///Por ejemplo, si el arreglo es de 10 elementos(0 a 9), el Final es 11, el principio 0
	int *NewArreglo= new int[NewSize]; ///Nuevo arreglo con nuevo tamaño
	int PosCambioArreglo= PosicionACambiarArreglo - PrincipioArreglo; ///Resto el valor para variar posicion con el principio, siguiendo el ejemplo, pos=2, 2-0 = 2
	int contador= 0;
	for(int i=0;i<NewSize;i++){
		if(PrincipioArreglo+i > PosicionACambiarArreglo){
			*(NewArreglo+contador) = *(PrincipioArreglo+i);
			contador++; ///Para aumentar y poder cambiar donde iria el valor del siguiente for
		}
	}
	for(int i=0;i<NewSize;i++){
		if(PrincipioArreglo+i <= PosicionACambiarArreglo){
			*(NewArreglo+contador) = *(PrincipioArreglo+PosCambioArreglo-i); ///Como es más chico o igual que el 2, el nuevo arreglo, tendra el valor del 0+2+0(Si nos ubicamos en la primera vuelta)
			contador++;
		}
	}
	return make_tuple(NewArreglo,NewSize);
}

int main() {
	cout<<"Ingrese el tamanio del arreglo: ";int tamanio;cin>>tamanio;
	int *principio= new int[tamanio];
	cout<<endl;
	
	cout<<"Vamos a llenar el vector"<<endl;
	int valor;
	for(int i=0;i<tamanio;i++){
		cout<<"Ingrese el valor del elemento "<<i<<": ";cin>>valor;
		*(principio+i)= valor;
	}
	cout<<endl;
	
	cout<<"Asi es su vector: ";
	for(int i=0;i<tamanio;i++){
		cout<<*(principio+i)<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Desde que posicion quiere cambiar su arreglo: ";int pos;cin>>pos;
	cout<<endl;
	
	int NewTamanio, *NewVector;
	///principio= 0;
	///pos= 2;
	///tamanio= 10;
	tie(NewVector,NewTamanio) = NuevoArreglo(principio,principio+pos,principio+tamanio+1); ///No tengo que pasar 3 punteros en si, sino que hay que enviar el puntero, más 2 modificaciones que sufra
	
	cout<<"Su nuevo arreglo es el siguiente: ";
	for(int i=0;i<NewTamanio;i++){
		cout<<*(NewVector+i)<<" ";
	}
	
	delete []NewVector;
	delete []principio;
	return 0;
}

