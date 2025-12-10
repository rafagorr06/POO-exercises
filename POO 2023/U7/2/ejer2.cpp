///Implemente una función Clamp(...) que reciba como parámetros una variable (po
///referencia) y dos valores indicando los límites superior e inferior para el valor de
///dicha variable. Si el valor de la variable supera su máximo, este debe ajustarse al
///máximo valor permitido. De la misma forma si el valor es inferior al mínimo. Pruebe
///la función templatizada desde un programa cliente.
#include <iostream>
using namespace std;

template<typename T>
T Clamp(T &x, T sup, T inf){
	if(x>sup){
		x= sup;
	}else if(x<inf){
		x= inf;
	}
	return x;
}

int main() {
	cout<<"Enteros"<<endl;
	cout<<"Valor ";int varint;cin>>varint;
	cout<<"Superior ";int supint;cin>>supint;
	cout<<"Inferior ";int infint;cin>>infint;
	
	cout<<"El valor de la variable es "<<Clamp(varint,supint,infint);
	
	cout<<endl;
	
	cout<<"Flotantes"<<endl;
	cout<<"Valor ";float varf;cin>>varf;
	cout<<"Superior ";float supf;cin>>supf;
	cout<<"Inferior ";float inff;cin>>inff;
	
	cout<<"El valor de la variable es "<<Clamp(varf,supf,inff);
	

	return 0;
}

