#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;
//b
void procesa_secuencia(vector<int>&contenedor, int& suma_parte1, int& suma_parte2) {
	//i
	if (contenedor.size()%2 != 0) {
		contenedor.erase(contenedor.begin()+contenedor.size() / 2);
	}
	int mitad = contenedor.size()/2;
	
	//ii
	vector<int>parte1(contenedor.begin(), contenedor.begin() + mitad);
	vector<int>parte2(contenedor.begin() + mitad, contenedor.end());
	
	sort(parte1.begin(),parte1.end());
	sort(parte2.begin(),parte2.end());
	
	suma_parte1 = accumulate(parte1.begin(),parte1.end(),0);
	suma_parte2 = accumulate(parte2.begin(),parte2.end(),0);
}
	
	
	
int main(int argc, char *argv[]) {
	//a
	ifstream archi("data20211104.txt");
	vector<int>contenedor;
	int numero;
	while (archi>>numero) {
		contenedor.push_back(numero);
	}
	archi.close();
	
	//b
	int suma_parte1;
	int suma_parte2;
	procesa_secuencia(contenedor, suma_parte1, suma_parte2);
	
	//c
	int promediodiv = contenedor.size()/2;
	cout<< "Promedio 1: "<< suma_parte1/promediodiv<<"Promedio 2: "<<suma_parte2/promediodiv<<endl;
	
	for(size_t i=0;i<contenedor.size();i++) { 
		cout<<contenedor[i]<<endl;
	}
	
	//d
	ofstream archi_salida("data20211104.txt");
	for(size_t i=0;i<contenedor.size();i++) { 
		archi_salida << numero << endl;
	}
	
	return 0;
}

