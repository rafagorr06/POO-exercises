#include <iostream>
using namespace std;

template <typename T>

int generaint(){return rand()%100;}
int generafloat(){return rand()%100/10.0;}
int generastring(){
	string s="";
	for(int i=0;i<5;i++) { 
		s= s+(char)(rand()%('z'-'a')+'a');
		return s;
	}
}

class VectorDinamico {
public:
	VectorDinamico (int ini) : tam_inicial (ini) {
		vec = new T[tam_inicial];
	}
	~VectorDinamico() {delete[] vec;}
	T& operator [] (int i) {
		return vec[i];
	}
	
	template<typename PF>
	VectorDinamico (int ini, PF (*f)()) : tam_inicial (ini) {
		vec = new T[tam_inicial];
		for(int i=0;i<tam_inicial;i++) { 
			vec[i]=f();
		}
	}
	
private:
	int tam_inicial;
	T* vec;
};

int main() {
	
	return 0;
}

