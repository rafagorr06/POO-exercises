#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Legajo{bool borrado; char ape[64], nom[64]; 
unsigned int dni, antiguedad;float salario;};

void limpiador(string nombrearchi){
	ifstream archi(nombrearchi, ios::binary|ios::in);
	
	vector<Legajo>datos;
	Legajo aux;
	
	while(archi.read(reinterpret_cast<char*>(&aux.borrado),sizeof(bool)) and 
		archi.read(reinterpret_cast<char*>(&aux.ape),sizeof(char)) and
		archi.read(reinterpret_cast<char*>(&aux.nom),sizeof(char)) and
		archi.read(reinterpret_cast<char*>(&aux.dni),sizeof(unsigned int)) and
		archi.read(reinterpret_cast<char*>(&aux.antiguedad),sizeof(unsigned int)) and
		archi.read(reinterpret_cast<char*>(&aux.salario),sizeof(float))){
		
		datos.push_back(aux);	
		
	};
	archi.close();
	
	for(auto it=datos.begin(); it != datos.end(); it++){
		if(it->borrado == true){
			it= datos.erase(it);
		}
	}
	
	ofstream archiout("nuevo.txt");
	for(int i=0;i<datos.size();i++){
		Legajo aux;
		archiout<<aux.ape<<" "<<aux.nom<<" "<<aux.dni<<" "<<aux.antiguedad<<" "<<aux.salario<<endl;
	}
}

bool verificardni(unsigned int adni){
	
	ifstream archinew("nuevo.txt");
	
	vector<Legajo>datos;
	Legajo aux;
	
	while(archinew>>aux.borrado and archinew>>aux.ape and archinew>>aux.nom and
		  archinew>>aux.dni and archinew>>aux.antiguedad and archinew>>aux.salario){
		datos.push_back(aux);
	}
	archinew.close();
	
	for(int i=0;i<datos.size();i++){
		if(datos[i].dni == adni){
			return true;
		}
	}
	return false;
}	

	int main() {
		
		return 0;
	}

