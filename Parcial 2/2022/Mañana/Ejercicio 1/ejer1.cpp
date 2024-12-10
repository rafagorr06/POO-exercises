#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct Datos{char tipo;float medicion;};

int main() {
	
	ifstream archiH("humedad.dat",ios::binary|ios::in);
	ifstream archiP("precipitaciones.dat",ios::binary|ios::in);
	ifstream archiT("temperatura.dat",ios::binary|ios::in);
	
	map<int,vector<Datos>>info;	///un map te deja ir a cualquier parte con una pos (linea 24)
	
	int fecha;
	
	Datos aux1;
	
	while(archiH.read(reinterpret_cast<char*>(&fecha),sizeof(fecha)) and
		  archiH.read(reinterpret_cast<char*>(&aux1.medicion),sizeof(aux1.medicion))){
		aux1.tipo= 'H';
		info[fecha].push_back(aux1);
	}
	
	Datos aux2;
	
	while(archiP.read(reinterpret_cast<char*>(&fecha),sizeof(fecha)) and 
		  archiP.read(reinterpret_cast<char*>(&aux2.medicion),sizeof(aux2.medicion))){
		aux2.tipo= 'P';
		info[fecha].push_back(aux2);
	}

	Datos aux3;
	
	while(archiT.read(reinterpret_cast<char*>(&fecha),sizeof(fecha)) and
		  archiT.read(reinterpret_cast<char*>(&aux3.medicion),sizeof(aux3.medicion))){
		aux3.tipo= 'T';
		info[fecha].push_back(aux3);
	}
	
	archiH.close();archiP.close();archiT.close();
	
	float may1 = aux1.medicion; float may2 = aux2.medicion; float may3 = aux3.medicion;
	
	float min1 = aux1.medicion; float min2 = aux2.medicion; float min3 = aux3.medicion;
	
	int prom1=0; int prom2=0; int prom3=0;
	
	int cant1=0; int cant2=0; int cant3=0;
	
	for(int i=0;i<info.size();i++){
		if(info[i].tipo=='H'){
			if(may1<(info[i].medicion)){ may1 = (info[i].medicion);}
			if(min1>(info[i].medicion)){ min1 = (info[i].medicion);}
			prom1 += (info[i].medicion);
			++cant1;
			break;
		}
		else if(info[i].tipo=='P'){
			if(may2<(info[i].medicion)){ may2 = (info[i].medicion)}
			if(min2>(info[i].medicion)){ min2 = (info[i].medicion)}
			prom2 += (info[i].medicion);
			++cant2;
			break;
		}
		else if(info[i].tipo=='T'){
			if(may3<(info[i].medicion)){ may3 = (info[i].medicion)}
			if(min3>(info[i].medicion)){ min3 = (info[i].medicion)}
			prom3 += (info[i].medicion);
			++cant3;
			break;
		}
	}
	return 0;
}

