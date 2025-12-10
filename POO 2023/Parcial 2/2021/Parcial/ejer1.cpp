#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
using namespace std;

tuple<int,int> procesa_secuencia(vector<int>&Info){
	if(Info.size()%2==1){
		Info.erase(Info.begin()+Info.size()/2);
	}
	
	auto it_medio = (Info.begin()+Info.size()/2);
	sort(Info.begin(),it_medio);
	sort(it_medio,Info.end());
	reverse(it_medio,Info.end());
	
	int sum1= accumulate(Info.begin(),it_medio,0);
	int sum2= accumulate(it_medio,Info.end(),0);
	
	return make_tuple(sum1,sum2);
}

int main() {
	
	ifstream archi_IN("data20211104.txt");
	vector<int>Datos;
	int valor;
	
	while(archi_IN>>valor){
		archi_IN>>valor;
		Datos.push_back(valor);
	}
	
	int suma1,suma2;
	tie(suma1,suma2)= procesa_secuencia(Datos);
	cout<<"Prom 1: "<<suma1/(Datos.size()/2)<<endl;
	cout<<"Prom 2: "<<suma2/(Datos.size()/2)<<endl;
	
	ofstream archi_OUT("datosM.txt");
	for(auto i: Datos){
		archi_OUT<<i<<endl;
	}
	return 0;
}

