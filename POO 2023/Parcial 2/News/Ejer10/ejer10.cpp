#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

template<typename T>
T eliminarrepe(string namearchi,T x){
	ifstream archi(namearchi,ios::binary|ios::in);
	
	vector<T>datos;
	T data;
	
	while(archi.read(reinterpret_cast<char*>(&data),sizeof(T))){
		datos.push_back(data);
	}
	
	sort(datos.begin(),datos.end());
	
	int n;
	for(auto x: datos){
		n =+ count(datos.begin(),datos.end(),x);
		unique(datos.begin(),datos.end());
	}
	return n;
}

int main() {
	
	return 0;
}

