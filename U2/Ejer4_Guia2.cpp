#include <iostream>
using namespace std;

	class VectorDinamico{
	private:
		int *v;
		int m_tamanio;
	public:
		VectorDinamico(int x){
			m_tamanio = x;
			v = new int [x];
			for(int i=0;i<x;i++){
				v[i]=rand()%100;
			}
		}
		void Duplicar(){
			int *p = new int [2*m_tamanio];
			for(int i=0;i<(2*m_tamanio);i++){
				if(i<m_tamanio){
					p[i] = *(v+1);
				}
				else{
					p[i] = 500 + rand()%1050;
				}
			}
			delete v;
			v=p;
		}
		int VerElemento(int x){
			return v[x];
		}
		~VectorDinamico(){
			delete []v;
		}
	};

int main() {
	int tam;
	cout<<"Tamanio de su vector: ";cin>>tam;
	VectorDinamico c1(tam);
	c1.Duplicar();
	
	for(int i=0;i<(2*tam);i++){
		cout<<c1.VerElemento(i)<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	int pos;
	cout<<"Posicion del elemento que queres ver: ";cin>>pos;	
	cout<<c1.VerElemento(pos-1); ///no cuento el cero, por eso siempre le resto 1, de lo contrarion veria el elemento de posicion 6
	
	return 0;
}

