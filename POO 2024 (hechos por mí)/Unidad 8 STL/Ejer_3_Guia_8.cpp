#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int randmio() {
	return 10+rand()%90;
}

int main() {
	srand(time(0));
	vector<int>v(30,rand()%25);
	generate(v.begin(),v.end(),randmio);
	
	//1
	sort(v.begin()+10,v.begin()+21);
	reverse(v.begin()+10,v.begin()+21);
	for(size_t i=0;i<v.size();i++) { 
		cout<<"v["<<i<<"]"<<"="<<v[i]<<""<<endl;
	}
	
	cout<< " " <<endl;
	
	//2
	vector<int>nuevo(10);
	for(int i=0;i<10;i++) { 
		nuevo[i]=v[i+11];
	}
	v.erase(v.begin()+10,v.begin()+21);
	for(size_t i=0;i<nuevo.size();i++) { 
		cout<<"Nuevo["<<i<<"]"<<"="<<nuevo[i]<<""<<endl;
	}
	cout<< " " <<endl;
	for(size_t i=0;i<v.size();i++) { 
		cout<<"v["<<i<<"]"<<"="<<v[i]<<""<<endl;
	}
	
	cout<< " " <<endl;
	
	//3
	cout<<"Ingrese un valor"<<endl;
	int valor;
	cin>>valor;
	cout<<count(v.begin(),v.end(),valor)<<endl;
	
	cout<< " " <<endl;
	
	//4
	remove(v.begin(),v.end(),valor);
	for(size_t i=0;i<v.size();i++) { 
		cout<<"v["<<i<<"]"<<"="<<v[i]<<""<<endl;
	}
	return 0;
}

