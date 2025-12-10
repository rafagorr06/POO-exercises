#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	vector<int>valores(3);
	
	//1
	for(size_t i=0;i<valores.size();i++) { 
		int valor;
		cout<<"Ingrese valor:"<<endl;
		cin>>valor;
		valores[i]=valor;
	}
	
	for(size_t i=0;i<valores.size();i++) { 
		cout<<valores[i]<<endl;
	}
	cout<< " " <<endl;
	for(auto it = valores.begin(); it != valores.end(); ++it) { 
		cout<<*it<<endl;
	}
	cout<< " " <<endl;
	for(int x:valores) {
		cout<<x<<endl;
	}
	cout<< " " <<endl;
	
	//2
	int max = *max_element(valores.begin(),valores.end());
	cout<<"El maximo es: "<<max<<endl;
		
	int min = *min_element(valores.begin(),valores.end());
	cout<<"El minimo es: "<<min<<endl;

	int suma= accumulate(valores.begin(),valores.end(),0);
	int prom= suma/valores.size();
	cout<<"El promedio es: "<<prom<<endl;
	
	sort(valores.begin(),valores.end());
	cout<<"La media es: "<<valores[valores.size()/2]<<endl;
	return 0;
	
}

