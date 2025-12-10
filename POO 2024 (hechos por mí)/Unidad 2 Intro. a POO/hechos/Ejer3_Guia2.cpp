#include <iostream>
#include <cmath>
using namespace std;

class polinomio{
	int *terminos; /// t�rminos del polinomio
	int grado;
	float valorx;
public:
	polinomio(){
		/// Hasta que no le setee un grado, el puntero apunta a Nulo
		terminos=nullptr;
	}
	polinomio(int gr, float x){
		terminos = new int[gr+1]; /// genero el vector de t�rminos
		for(int i = 0;i<=gr;i++){
			terminos[i] = 0; /// ponerlos en 0
		}
		valorx=x;grado=gr;
	}
	~polinomio(){delete [] terminos;}
    void CargarValorX(float x){valorx=x;}
	string VerPolinomio(){
		string aux = "";
		for(int i = grado;i>=0;i--){
			if(i==0){
				if(terminos[i] >=0){
					aux += " + ";}
				else{
					aux += " ";
				}
			
				aux += to_string(terminos[i]);}
			else{
				if(aux!=""){
					if(terminos[i] >=0){
						aux += " + ";}
					else{
						aux += " ";
					}
				}
				aux += to_string(terminos[i]);
				if(i == 1){
					aux += "X ";}
				else{
					aux += "X^";
					aux += to_string(i);
				}
			}
		}
		return aux;
	}
	void CargarTermino(int gr,float valor){
		if (terminos != nullptr){
			terminos[gr] = valor;
		}
		
	}
	float VerSuma(){
		float suma = terminos[0];
		for(int i = 1;i<=grado;i++){
			suma += pow(valorx,i) * terminos[i];
		}
			
		return suma;
	}
	float VerValorX(){
		return valorx;
	}
};

int main() {
	polinomio p(4,6);
	p.CargarTermino(0,23);
	p.CargarTermino(1,6);
	p.CargarTermino(2,-12);
	p.CargarTermino(3,4);
	p.CargarTermino(4,21);
	cout<<"Valor de X : "<<p.VerValorX()<<endl<<endl;
	cout<<p.VerPolinomio()<<"  = "<<p.VerSuma();
	return 0;
}

