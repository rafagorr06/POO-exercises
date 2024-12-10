#include <iostream>
using namespace std;
//a es puntero, n es cantidad, M es numero a insertar, P es posicion a insertar
int *insertar(int *ptr, int n, int m,int p) {
	int *ptr2=new int[n+1];
	for(int i=0;i<n;i++){
		if(i<p) {
			*(ptr2+i)=*(ptr+i);
		}else {
			*(ptr2+i+1)=*(ptr+i); //esto crea un nuevo puntero (elimina el vector anterior para crear uno nuevo) por eso se crea un nuevo puntero
		}
}
	*(ptr2+p)=m;
	delete ptr;
	return ptr2;}

int main() {
	cout<<"Ingrese la cantidad de numeros que desea en el vector: "<<endl;
	int n; cin>>n;
	int *a=new int [n];
	for (int i=0;i<n;i++) {
		*(a+i)=rand()%501+1000;
	}
	cout<<"Lista de numeros aleatorios: "<<endl;
	for (int i=0;i<n;i++) {
		cout<<*(a+i)<<endl;
	}
	/*int *may;
	*may=0;
	for (int i=0;i<n;i++) { //consultar 
		if(*(a+i)>*may)  {
			may=(a+i);
		}
	}
	cout<<"El numero mayor de la lista es: "<<endl<<*may;*/
	cout<<"Ingrese el numero que desea insertar: "<<endl;
	int m;cin>>m;
	cout<<"Ingrese en la posicion que lo desea insertar: "<<endl;
	int p;cin>>p;
	cout<<"El vector con el numero insertado es: "<<endl;
	int *b;
	b=insertar(a,n,m,p);
	for (int i=0; i<n;i++) {
		cout<<*(b+i)<<endl;
	}
	
	
	delete a;
	return 0;
}

