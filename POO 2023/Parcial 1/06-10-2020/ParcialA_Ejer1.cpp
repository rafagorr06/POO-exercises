#include <iostream>
using namespace std;
int* intercala(int *v1, int *v2, int tamanio1, int tamanio2){
	int n;
	if (tamanio1>tamanio2){
		n=tamanio1;
	}else{
		n=tamanio2;
	}
	int *nv=new int[(tamanio1+tamanio2)];
	int cont=0;
	for(int i=0;i<n;i++) { 
		if(i<tamanio1){
			*(nv+cont)=*(v1+i);
			cont++;
		}
		if(i<tamanio2){
			*(nv+cont)=*(v2+i);
			cont++;
		}
	}
	return nv;
}
int main() {
	cout<<"Ingrese el tamaño del primer vector"<<endl;int n1;cin>>n1;
	int *v1=new int [n1];
	
	for(int i=0;i<n1;i++) { 
		*(v1+i)=rand()%100;		///lleno aleatoriamente
		cout<<*(v1+i)<<"  ";
	}
	
	cout<<endl<<"Ingrese el tamaño del segundo vector"<<endl;int n2;cin>>n2;
	int *v2=new int [n2];
	
	for(int i=0;i<n2;i++) { 
		*(v2+i)=rand()%100;		///lleno aleatoriamente
		cout<<*(v2+i)<<"  ";
	}
	
	cout<<endl;
	
	int *nv=intercala(v1,v2,n1,n2);
	for(int i=0;i<(n1+n2);i++) { 
		cout << *(nv+i) << "   ";
	}
	
	delete []v1;
	delete []v2;
	delete []nv;
	return 0;
}

