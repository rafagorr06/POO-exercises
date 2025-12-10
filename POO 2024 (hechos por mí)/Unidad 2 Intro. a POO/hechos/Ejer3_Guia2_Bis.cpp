#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class polinomio{
	vector<int>terminos; /// términos del polinomio
	int grado;
public:
	
	polinomio(int gr){
		terminos.resize(gr+1,0); /// genero el vector de términos
		
		grado=gr;
	}
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
		terminos[gr] = valor;
		
	}
	float VerSuma(float x){
		float suma = terminos[0];
		for(int i = 1;i<=grado;i++){
			suma += pow(x,i) * terminos[i];
		}
			
		return suma;
	}
	
};

int main() {
	polinomio p(4);
	p.CargarTermino(0,23);
	p.CargarTermino(1,6);
	p.CargarTermino(2,-12);
	p.CargarTermino(3,4);
	p.CargarTermino(4,21);
    
	int x;
	cout<<"Ingrese valor de x : ";cin>>x;
	cout<<endl<<endl;
	cout<<p.VerPolinomio()<<"  = "<<p.VerSuma(x);
	return 0;
}

