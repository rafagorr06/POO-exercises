#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ficha{bool borrado;int dni;char nombre[50];float h;};

bool operator<(Ficha a, Ficha b){ return (a.dni<b.dni);}
bool operator>(Ficha a, Ficha b){ return (a.dni>b.dni);}


int main() {

	ifstream archir("register.dat",ios::binary|ios::in);
	
	vector<Ficha>fichero;
	Ficha aux;
	
	while(archir.read(reinterpret_cast<char*>(&aux.borrado),sizeof(bool) and
		archir.read(reinterpret_cast<char*>(&aux.dni),sizeof(int)) and 
		archir.read(reinterpret_cast<char*>(&aux.nombre),sizeof(char)) and 
		archir.read(reinterpret_cast<char*>(&aux.h),sizeof(float)))){
		fichero.push_back(aux);
	}
	archir.close();
	
	
	for(int i=0;i<fichero.size();i++){
		if(fichero[i].borrado == true){
			fichero.erase(i);
		}
	}
	
	sort(fichero.begin(),fichero.end());
	
	
	
	return 0;
}

