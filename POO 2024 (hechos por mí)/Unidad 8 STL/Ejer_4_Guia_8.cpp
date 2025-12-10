#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float>lista;
	float valor;
	cout<<"Ingrese un valor: "<<endl;
	cin>>valor;
	
	while (valor !=0.0){
	lista.push_back(valor);
	cout<<"Ingrese un valor: "<<endl;
	cin>>valor;
	}
	
	for(int i=0;i<lista.size();i++) { 
		cout<<"Lista["<<i<<"]"<<"="<<lista[i]<<""<<endl;
	}
	
	cout<<" "<<endl;
	
	for(int i=0;i<lista.size;i++) { 
		lista.insert()
	}
	lista.insert()
	return 0;
}

