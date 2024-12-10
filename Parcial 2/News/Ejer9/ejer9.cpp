#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<class T>
class Puntuacion{
private:
	string jugador; T puntaje;
public:
	Puntuacion(string pj, T pt){
		jugador= pj;
		puntaje= pt;
	}
};

//template<class T>
class MejoresPunt{
private:
	vector<Puntuacion>mp;
public:
	MejoresPunt(int tamanio,string namearchi){
		ifstream archi(namearchi);
		
		string player; int valor;
		
		while(archi>>player and archi>>valor){
			Puntuacion p(player,valor);
			mp.push_back(p);
		}
	}
};








int main() {
	
	return 0;
}

