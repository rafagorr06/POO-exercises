#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
struct puntaje{
	char nombre[9];
	int puntos;
};
ostream &operator <<(ostream &o,puntaje c){
	o<< c.nombre << " ----> " << c.puntos;
	return o;
}
class Puntuaciones{
private:
	string ruta;
	vector <puntaje> v;
	int n;
public:
	Puntuaciones(string direccion):ruta(direccion){
		ifstream archi(ruta,ios::binary|ios::in|ios::ate);
		n=archi.tellg()/sizeof(puntaje);
		archi.seekg(0);
		for(int i=0;i<n;i++) { 
			puntaje a;
			archi.read(reinterpret_cast<char*>(&a),sizeof(puntaje));
			v.push_back(a);
			cout << a << endl;
		}
	}
	bool Agregar(puntaje nuevo){
		bool ingreso=false;
		int pos;
		for(int i=0;i<n;i++) { 
			if(nuevo.puntos>v[i].puntos){
				pos=i;
				ingreso=true;
				break;
			}
		}
		if(!ingreso)return false;
		for(int i=n;i>pos;i--) { 
			v[i].puntos=v[i-1].puntos;
			strcpy(v[i].nombre,v[i-1].nombre);
		}
		v[pos].puntos=nuevo.puntos;
		strcpy(v[pos].nombre,nuevo.nombre);
		ofstream archi(ruta,ios::binary|ios::trunc|ios::out);
		for(int i=0;i<n;i++) { 
			archi.write(reinterpret_cast<char*>(&v[i]),sizeof(puntaje));
		}
		return ingreso;
	}
	puntaje Consultar(int pos){
		
		return v[pos];
	}
};
int main() {
	cout << "Ingrese la cantidad de posiciones de la tabla"<<endl;
	int n;cin >> n;
	ofstream archi("puntosjuego.poo",ios::binary|ios::out|ios::in|ios::trunc);
	vector <puntaje> v;
	for(int i=0;i<n;i++) { 
		puntaje a;
		string jugador="jugador"+to_string(i);
		strcpy(a.nombre,jugador.c_str());
		a.puntos=rand()%100+15;
		v.push_back(a);
	}
	vector <puntaje> v2(n);
	for(int i=0;i<n;i++) { 
		for(int j=0;j<n;j++) { 
			if(v[i].puntos>=v2[j].puntos){
				for(int x=n;x>j;x--){
					strcpy(v2[x-1].nombre,v2[x-2].nombre);
					v2[x-1].puntos=v2[x-2].puntos;
				}
				strcpy(v2[j].nombre,v[i].nombre);
				v2[j].puntos=v[i].puntos;
				break;
			}
		}
	}
	for(int i=0;i<n;i++) { 
		puntaje a;
		strcpy(a.nombre,v2[i].nombre); a.puntos=v2[i].puntos;
		archi.write(reinterpret_cast<char*>(&a),sizeof(a));
		cout << a <<endl;
	}
	archi.close();
	cout << "Ingrese el nombre de jugador ejemplo: MegaMax (MAXIMO 8 CARACTERES" << endl;
	puntaje nuevo; string jugador; cin >> jugador;
	while(jugador.length()>8){
		cout << "NOMBRE DEMASIADO GRANDE"<<endl;
		cin >> jugador;
	}
	strcpy(nuevo.nombre,jugador.c_str());
	cout << "Ingrese la nueva puntuación"<<endl; cin >> nuevo.puntos;
	Puntuaciones P1("puntosjuego.poo");
	if(P1.Agregar(nuevo)){
		cout << "El jugador ha ingresado al top5 BEST PLAYERS" << endl;
	}else{
		cout << "SEGUI PARTICIPANDO...No entraste al top5 BEST PLAYERS"<<endl;
	}
	for(int i=0;i<5;i++) { 
		cout<<P1.Consultar(i)<<endl;
	}
	return 0;
}

