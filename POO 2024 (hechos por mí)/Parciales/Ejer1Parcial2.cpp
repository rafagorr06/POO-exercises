#include <iostream>// inlcuir librerias aqui#include <fstream>
using namespace std;struct Legajo {bool borrado; char nom[60],ape[60];};

void nuevoarchi(string  nombrearchib,nombrearchit){  
	ifstream archi(nombrearchi,ios::binary|ios::ate);	int N=tam/size(Legajo);	archi.seekg(0);	vector<Legajo> v,b; Legajo dato;
		while (archi.read(reinterpret_cast<char*>(&dato),sizeof(dato)){		 v.push_back(dato);
	}	archi.close();	
		ofstream archi("clientes.dat",ios::binary)|ios::trunc);	for (size_t i=0; i<v.size(); ++i){	if (!v.borrado){		archi.write(reinterpret_cast<char*>(&v[i],sizeof(Legajo))    			archi.close();}		dni_elim(v,nombrearchit);}	
}int main(int argc, char *argv[]) {	string nomfile;	getline(cin,  nomfileb);	getline(cin, nomfilet);	nuevoarchi(nomfile);		return 0;}
