///Implemente una función templatizada llamada Mayor(...) que reciba dos valores y
///devuelva el mayor. Compruebe el correcto funcionamiento de la rutina probándola
///desde un programa cliente con valores de tipo int, float y string.
///a. Programe una sobrecarga de la función Mayor(...) que reciba un vector y
///retorne el mayor elemento del mismo. Pruebe la función sobrecargada
///desde un programa cliente con diversos tipos de datos.
///b. Responda: ¿Servirán las funciones anteriores con datos del tipo mostrado
///en el recuadro? Justifique su respuesta.
///Implemente los cambios necesarios, utilizando su propio criterio, para que
///las funciones desarrolladas funcionen con el tipo de dato del recuadro.

#include <iostream>
#include <vector>
using namespace std;

struct Persona{ string nombre, apellido; int dni;};


template<typename T>
T mayor(T n1, T n2){			///Programo para int, luego cambio por T
	if(n1>n2){
		return n1;
	}else{
		return n2;
	}
}

template<typename T>
T mayor(const vector<T>&x){		///A
	T may=0;
	for(T i=0;i<x.size();i++){
		if(may<x[i]){
			may= x[i];
		}
	}
	return may;
}

int main() {
	cout<<"Int 1: ";int n1;cin>>n1;
	cout<<"Int 2: ";int n2;cin>>n2;
	cout<<"El mayor es: "<<mayor(n1,n2);
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	cout<<"Float 1: ";float f1;cin>>f1;
	cout<<"Float 2: ";float f2;cin>>f2;
	cout<<"El mayor es: "<<mayor(f1,f2);
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	cout<<"String 1: ";string s1;cin>>s1;
	cout<<"String 2: ";string s2;cin>>s2;
	cout<<"El mayor es: "<<mayor(s1,s2);
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	vector<int>enteros(5);
	for(int i=0;i<enteros.size();i++){
		cout<<"valor entero "<<i<<": ";cin>>enteros[i];
	}
	cout<<"El mayor es: "<<mayor(enteros);
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	vector<float>flotante(5);
	for(int i=0;i<flotante.size();i++){
		cout<<"valor flotante "<<i<<": ";cin>>flotante[i];
	}
	cout<<"El mayor es: "<<mayor(flotante);
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	Persona A;
	cout<<"Nombre A: ";cin>>A.nombre;
	cout<<"Apellido A: ";cin>>A.apellido;
	cout<<"DNI A: ";cin>>A.dni;
	
	cout<<endl<<"-----------------------------------------"<<endl;
	
	Persona B;
	cout<<"Nombre B: ";cin>>B.nombre;
	cout<<"Apellido B: ";cin>>B.apellido;
	cout<<"DNI B: ";cin>>B.dni;
	
	cout<<"El mayor es: "<<mayor(A.dni,B.dni);
	
	return 0;
}

