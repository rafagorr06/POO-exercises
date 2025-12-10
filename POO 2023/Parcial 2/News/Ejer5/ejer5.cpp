#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	
	ifstream archipaq("paquete.txt");
	
	vector<string>paquetes;
	string paq;
	
	while(getline(archipaq,paq)){
		paquetes.push_back(paq);
	}
	archipaq.close();
	
	for(auto x: paquetes){
		cout<<x<<endl;
	}
	
	for(int i=0;i<paquetes.size();i++){
		if(paquetes[i] == "paquete"){
			paquetes[i] = "aplicacion";
		}
	}
	
	ofstream archiapp("paquete.txt");
	for(int i=0;i<paquetes.size();i++){
		archiapp<<paquetes[i]<<endl;
	}
	
	return 0;
}

