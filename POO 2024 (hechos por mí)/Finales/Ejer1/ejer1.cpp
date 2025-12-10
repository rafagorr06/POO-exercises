#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
void eliminarElementosArchivo(string nombrearchi,vector<int>pos){
	ifstream archi(nombrearchi, ios::binary|ios::in);
	
	vector<T>datos;
	T data;
	
	while(archi.read(reinterpret_cast<char*>(&data),sizeof(T))){
		datos.push_back(data);
	}
	archi.close();
	
	for(auto it=datos.begin(); it != datos.end(); it++){
		if(it != pos[it]){
			datos.erase(it);
		}
	}
	
	ofstream archout(nombrearchi, ios::binary|ios::out|ios::trunc);
	for(int i=0;i<datos.size();i++){
		archout<<datos[i]<<endl;
	}
}


int main() {
	
	return 0;
}

