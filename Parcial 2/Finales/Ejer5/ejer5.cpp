#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T obtener_maximo(vector<T>x, T predicado){
	T may=
}

template<typename T>
bool es_par(T x){ return x%2==0;}

int main() {
	
	vector<int>v = {9,4,8,5,7};
	cout<<obtener_maximo(v,es_par);
	
	return 0;
}

