#include <iostream>
#include <fstream>
using namespace std;

template<typename T>
void buscarreemplazar(string nomarchi, T va, T vb){
	fstream archi(nomarchi, ios::binary);
	
	T valor;
	for(int i=0;i<50;i++){
		archi.read(reinterpret_cast<char*>(&valor),sizeof(valor));
		if(valor==va){
			valor= vb;
		}
		archi.write(reinterpret_cast<char*>(&valor),sizeof(valor));
	}
}

int main() {
	
	return 0;
}

