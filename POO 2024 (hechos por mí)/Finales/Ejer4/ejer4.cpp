#include <iostream>
using namespace std;

template<class T>
class Rango{
private:
	T mayor; T minimo;
public:
	Rango(T maximo, T menor){
		mayor = maximo;
		minimo = menor;
	}
	bool validar(){
		if(minimo>mayor){
			return false;
		}
		return true;
	}
	T verMax(){
		return mayor;
	}
	T verMin(){
		return minimo;
	}
};

template<typename T>
bool verificar(T aux, T var){
	if(var>aux.verMin and var<aux.verMax){
		return true;
	}
	return false;
}

int main() {
	
	return 0;
}

