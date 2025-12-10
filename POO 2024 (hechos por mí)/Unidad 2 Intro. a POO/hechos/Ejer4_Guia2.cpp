#include <iostream>
#include <cstdlib>
using namespace std;

class VectorDinamico{
	int *v;
	int size;
	
public:
	VectorDinamico(){
		v=nullptr;size=0;
	}
	VectorDinamico(int n){
		v = new int[n];
		for(int i = 0;i<n;i++){
			v[i] = 100 + rand() % 500;
		}
		size = n;
	}
	VectorDinamico(const VectorDinamico & vv){
			size = vv.size;
			v = new int[size];
			for(int i = 0;i<size;i++){
				v[i] = vv.v[i];
			}
	}
	~VectorDinamico(){delete []v;}
	void Duplicar(){
		int *aux = new int[size*2]; /// duplico el espacio
		for(int i = 0;i<size;i++){
			aux[i] = v[i];
		}
		/// rellenar con ceros
		for(int i = size;i<(size*2);i++){
			aux[i] = 100 + rand() % 500;
		}
		size = size * 2;
		delete []v;v=aux;
	}
	int Tamanio(){
		return size;
	}
	int VerElemento(int pos){return v[pos];}
};

int main() {
	VectorDinamico v(10);
	for(int i = 0;i<v.Tamanio();i++){
		cout<<v.VerElemento(i)<<"   ";
	}
	v.Duplicar();
	cout<<endl<<endl;
	if (v.Tamanio() > 0){
		VectorDinamico v2 = v;
		for(int i = 0;i<v2.Tamanio();i++){
			cout<<v2.VerElemento(i)<<"   ";
		}
	}
	cout<<endl<<endl;
	for(int i = 0;i<v.Tamanio();i++){
		cout<<v.VerElemento(i)<<"   ";
	}
	cout<<endl<<endl;
	cout<<"v2"<<endl;
	VectorDinamico v2= v;
	for(int i = 0;i<v.Tamanio();i++){
		cout<<v2.VerElemento(i)<<"   ";
	}
	return 0;
}

