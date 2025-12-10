#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

template<typename T>

class Calculos{

private:
	int tamanio;
	vector<T>valores;
public:
	Calculos(int tam) : tamanio(tam){}
	
	void AgregarDatos(T n){
		valores.push_back(n);
	}
	
	int VerValor(int i){
		return valores[i];
	}
	
	tuple<T,T>dosmax(){
		T may1=0; T may2=0;
		for(int i=0;i<valores.size();i++){
			if(valores[i] > may1){
				may1= valores[i];
				may2= may1;
			}else if(valores[i] > may2){
				may2= valores[i];
			}
		}
		return make_tuple(may1,may2);
	}
	
};

int main() {
	
	cout<<"Tamanio: ";int tam;cin>>tam;
	Calculos c1(tam);
	cout<<endl;
	
	for(int i=0;i<tam;i++){
		cout<<"Valor: ";int s;cin>>s;
		c1.AgregarDatos(s);
	}
	cout<<endl;
	
	cout<<"Siempre pos par ver su valor: ";int i;cin>>i;
	cout<<"Valor: "<<c1.VerValor(i);
	cout<<endl;
	
	int may1,may2;
	tie(may1,may2) = c1.dosmax();
	cout<<"May valores: "<<may1<<" y "<<may2<<endl;
	
	
	return 0;
}

