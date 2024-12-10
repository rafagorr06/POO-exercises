#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template<typename T>
void eliminaObjetos(string nombre, vector<int>posiciones){
	
	ifstream archi(nombre, ios::binary|ios::in);
	
	vector<T>datos;
	T data;
	
	while(archi.read(reinterpret_cast<char*>(&data),sizeof(T))){
		datos.push_back(data);
	}
	archi.close();
	
	for(int i=0;i<datos.size();i++){
		if(i != posiciones[i]){
			datos.erase(i);
		}
	}
	
	ofstream archiout(nombre, ios::binary|ios::out);
	
	for(int i=0;i<datos.size();i++){
		archiout.write(reinterpret_cast<char*>(&datos[i]),sizeof(T));
	}	
}

int main() {
	
	return 0;
}

