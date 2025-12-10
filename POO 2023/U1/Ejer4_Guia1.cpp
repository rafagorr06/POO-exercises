#include <iostream>
using namespace std;

*buscar(int *ptr,int cant, int x) { 
	for (int i=0; i<cant;i++) {
		if (x==ptr[i]) {
			return &(ptr[i]);
		}
	}
	return nullptr;
}

int main() {
	int n;cin>>n;
	int *p=new int [n];
	for (int i=0;i<n;i++) {
		p[i]=i+1;
	}
	
	cout<<"Lista de numeros: "<<endl;
	for (int i=0;i<n;i++) {
		
		cout<<p[i]<<endl;
	}
	cout<<"Ingrese el numero que desea saber en que posicion se encuentra"<<endl; 
	
	int x;cin>>x;
	int *v1;
	v1=buscar(p,n,x);
	
	if (v1==nullptr) {
		cout<<"El numero que ingreso no pertenece a la lista :( "<<endl;
	}else { 
		cout<<"El numero esta en la posicion: "<<v1-p<<endl;
	}
	delete []p;
	
	return 0;
}

