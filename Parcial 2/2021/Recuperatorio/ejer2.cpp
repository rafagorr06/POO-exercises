#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
struct Usuario{
	int dni;
	string ape,nom;
};
bool ComparaApe(Usuario a, Usuario b){
	return (a.ape==b.ape);
}
class LectorUsuarios{
	vector<Usuario>v;
	string direccion;
public:
	LectorUsuarios(string ruta):direccion(ruta){
		ifstream archi_in(ruta);
		Usuario a; string s;
		while(archi_in>>a.dni,getline(archi_in,s)){
			int pos=s.find(",",1);
			a.ape=s.substr(1,pos-1);
			a.nom=s.substr(pos+1);
			v.push_back(a);
		}
	}
	void Iniciales_Mayusculas(){
		for(size_t i=0;i<v.size();i++) {
			//Arregla apellido
			v[i].ape[0]=toupper(v[i].ape[0]);
			for(size_t j=1;j<v[i].ape.size();j++) { 
				v[i].ape[j]=tolower(v[i].ape[j]);
			}
			auto p=v[i].ape.find(" ",1);
			if(p!=string::npos){
				v[i].ape[p]=toupper(v[i].ape[p]);
			}
			//Arregla nombre
			v[i].nom[0]=toupper(v[i].nom[0]);
			for(size_t j=1;j<v[i].nom.size();j++) { 
				v[i].nom[j]=tolower(v[i].nom[j]);
			}
			p=v[i].nom.find(" ",1);
			if(p!=string::npos){
				v[i].nom[p]=toupper(v[i].nom[p]);
			}
		}
	}
	void ordenar(){
		sort(v.begin(),v.end(),ComparaApe);
	}
	void Reescribir(){
		ofstream archi_out(direccion,ios::trunc);
		for(size_t i=0;i<v.size();i++) { 
			archi_out<<v[i].dni<<","<<v[i].ape<<","<<v[i].nom<<endl;
		}
	}
};
int main() {
	
	return 0;
}

