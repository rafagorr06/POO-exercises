#include <iostream>
#include <list>
#include <numeric>
using namespace std;

struct Complejo {
	float p_real, p_imag;
};

template <typename T>

T promedio (list<T>x){
	T suma = accumulate(x.begin(),x.end(),0);
	T promedio = suma/x.size();
	return promedio;
};


list<Complejo> LeerComplejo(string nombrearchi,){
	vector<Complejo>
}
	
	
int main() {
	
	cin>>cantidad;
	
	//i
	list<float>listf;
	for(int i=0;i<cantidad;i++) { 
		cin>>flotante;
		listf.push_back(flotante);
	}
	promedio(listf);
	
	//ii
	list<int>listi;
	for(int i=0;i<cantidad;i++) { 
		listi.push_back(rand()%101);
	}
	promedio(listi);
	
	//iii
	list<Complejo>listc;
	
	
	
	return 0;
}

