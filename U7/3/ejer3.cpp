///Programe una clase templatizada llamada VectorDinamico (similar a la de la guía 2). 
///La clase debe poseer:
///a. Un constructor que reciba el tamaño inicial del vector, y reserve la memoria necesaria.
///b. Un destructor que se encargue de liberar la memoria reservada.
///c. Una sobrecarga del operador[] que reciba el número de elemento, devuelva su valor, y permita modificarlo.
///d. Modifique o sobrecargue el constructor para que permita generar valores
///aleatorios con los cuales inicializar las posiciones del arreglo que reserva.
///e. Utilice la clase desde un programa cliente creando vectores aleatorios con diversos tipos de datos (int,double,string, etc)	

#include <iostream>
using namespace std;

template<class T>
class VectorDinamico{
private:
	T *memoria;
public:
	VectorDinamico(int tam):memoria(nullptr){
		memoria= new T[tam]; ///reservo la memoria, con puntero
		for(int i=0;i<tam;i++){
			memoria[i]= (rand()%(89)+100); ///valores
		}
	}
	
	T operator[](int n)const{				///este operator[] es para ver el valor
		return(*(memoria+n));
	}
	
	T &operator[](int n){					///este operator[] es para modificar el valor
		return(*(memoria+n));
	}

	~VectorDinamico(){
		delete[]memoria;
	}
};

int main() {
	cout<<"Tamaño del vector: ";int tamanio;cin>>tamanio;
	VectorDinamico(tamanio);

	return 0;
}

