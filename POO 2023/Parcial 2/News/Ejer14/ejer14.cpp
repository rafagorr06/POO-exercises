#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>

void intercambia(string nombrearchi, int pos1, int pos2){
	ifstream archi(nombrearchi,ios::binary|ios::in);
	
	vector<T>datos;
	T data;
	
	while(archi>>data){
		datos.push_back(data);
	}
	archi.close();
	
	swap(datos[pos1],datos[pos2]);
	
	ofstream archiout(nombrearchi,ios::trunc);
	for(int i=0;i<datos.size();i++){
		archiout<<datos[i]<<endl;
	}
}
	
int main() {
	
	return 0;
}

