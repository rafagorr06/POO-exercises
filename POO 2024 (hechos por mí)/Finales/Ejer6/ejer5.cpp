#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct par{int x, y;};

template<typename T>
void invertir(string nomarchi){
	ifstream archi(nomarchi, ios::binary|ios::in);
	
	vector<T>datos;
	T data;
	
	while(archi.read(reinterpret_cast<char*>(&data),sizeof(T))){
		datos.push_back(data);
	}
	archi.close();
	
	reverse(datos.begin(),datos.end());
	
	ofstream archiout(nomarchi,ios::binary|ios::out|ios::trunc);
	for(int i=0;i<datos.size();i++){
		archiout<<datos[i]<<endl;
	}
}

int main() {
	
	return 0;
}

