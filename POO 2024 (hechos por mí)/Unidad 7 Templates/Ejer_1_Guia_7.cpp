#include <iostream>
#include <vector>
using namespace std;

struct Persona {
	string nombre;
	string apellido;
	int dni;
};

template <typename T>
T mayor (T x, T y) {
	if (x>y) {return x;} else {return y;}
}

template <typename T>
	T mayor (vector<T>v) {
	T m = v[0];
	for(size_t i=0;i<v.size();i++) { 
		if(v[i]>m) {
			m=v[i]; 
		}
	}
	return m;
}

bool operator > (Persona x, Persona y) {
	return x.dni<y.dni;
}
	
int main() {
	cout<<mayor(3,8)<<endl;
	cout<<mayor("hola","chau")<<endl;
	
	vector<int>vint= {0,4,3,6,8,56,3,2,4};
	vector<string>vstring= {"hola","chau","tres","tree","adios"};
	cout<<mayor(vint)<<endl;
	cout<<mayor(vstring)<<endl;
	return 0;
}

