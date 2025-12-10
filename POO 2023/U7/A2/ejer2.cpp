///Desarrolle una función Intercambia(...) que reciba dos variables por referencia e
///intercambie sus valores. Pruebe la función desde un programa cliente con al
///menos dos tipos de dato distintos

#include <iostream>
#include <tuple>
using namespace std;

template<typename T>
tuple<T,T>Intercambia(T &x1, T &x2){
	swap(x1,x2);
	return make_tuple(x1,x2);
}

int main() {
	
	cout<<"Enteros"<<endl;
	int i1, i2;
	cout<<"Int1: ";cin>>i1;
	cout<<"Int2: ";cin>>i2;
	
	int ic1,ic2;
	tie(ic1,ic2) = Intercambia(i1,i2);
	
	cout<<"Nuevo Int1: "<<ic1<<endl;
	cout<<"Nuevo Int2: "<<ic2<<endl;
	
	cout<<endl;
	
	cout<<"Flotantes"<<endl;
	float f1, f2;
	cout<<"F1: ";cin>>f1;
	cout<<"F2: ";cin>>f2;
	
	float fc1,fc2;
	tie(fc1,fc2) = Intercambia(f1,f2);
	
	cout<<"Nuevo F1: "<<fc1<<endl;
	cout<<"Nuevo F2: "<<fc2<<endl;	
	
	
	return 0;
}

