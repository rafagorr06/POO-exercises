#include <iostream>
#include <tuple>
using namespace std;

tuple<int*,int>ArregloModificado(int *Principio, int *PrimerPt, int *SegundoPt, int *Final){
	int n= Final-Principio; ///Calculo el tamanio total
	int m= SegundoPt-PrimerPt+1; ///Calculo la cantidad de los elementos que no van en el nuevo arreglo, se le suma 1, por que el SegundoPt debe estar incluido
	int *q= new int[n-m]; ///El nuevo tamanio es la resta del total con los elementos no incluidos
	int contador= 0;
	for(int i=0;i<n;i++){
		if((Principio+i)<PrimerPt or (Principio+i)>SegundoPt){
			q[contador] = Principio[i];
			++contador;
		}
	}
	return make_tuple(q,(n-m));
}

int main() {
	cout<<"Tamanio: ";int tamanio;cin>>tamanio;
	int *p= new int[tamanio];
	cout<<endl;
	
	int valor;
	cout<<"Llenado"<<endl;
	for(int i=0;i<tamanio;i++){
		cout<<"Valor nro "<<i<<" ";cin>>valor;
	}
	cout<<endl;
	
	cout<<"Su vector es este: ";
	for(int i=0;i<tamanio;i++){
		cout<< *(p+i)<<" ";
	}
	cout<<endl;
	
	for(int j=0;j<10;j++){ ///Se repite 10 veces
		int *q, m;
		int *p1= p+rand()%tamanio; ///Valor aleatorio para el primer corte
		int *p2= p+rand()%tamanio; ///Valor aleatorio para el segundo corte
		if(p2<p1){swap(p1,p2);} ///Si el p1 es mayor a p2, lo doy vuelta con esta funcion o con un aux
		tie(q,m)= ArregloModificado(p,p1,p2,p+m);
		for(int i=0;i<m;i++){
			cout<<*(q+i)<<" ";
		}
		cout<<endl;
		delete []q;
	}
	
	delete []p;	
	return 0;
}

