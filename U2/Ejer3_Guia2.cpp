#include <iostream>
#include <vector>
using namespace std;
/*Diseñe una clase Polinomio cuyos atributos sean el grado (entero) y los
coeficientes de los términos (hasta 20 términos; utilice un vector estático o la clase
vector, pero no new/delete). La clase debe tener:
a. un constructor que reciba el grado el polinomio e inicialice sus coeficientes
en 0.
b. un método que permita cambiar un coeficiente.
c. un método evaluar que permita evaluar el polinomio para un valor dado de
la variable x.
d. el/los métodos que considere necesarios para poder mostrar un polinomio
desde un programa cliente.
e. una función que permita sumar dos polinomios retornando un tercer
polinomio con el resultado (ej. p_res=Sumar(p1,p2);). ¿Cómo variaría si en
lugar de ser una funcin libre fuera un método de la clase?
Verifique el funcionamiento de la función Sumar(...) mediante un programa cliente.
*/
class Polinomio{
private:
	int grado;
	int v[20];
	int evaluado;
public:
	Polinomio(int _grado){
		grado=_grado;
		for (int i=0;i<20;i++){
			v[i]=0;
		}
	}
	void CambiarCoeficiente(int coef, int nuevo){
		v[coef]=nuevo;
	}
	int Evaluar(int x){
		evaluado=v[0];							
		for (int i=1;i<grado;i++){ ///arranca desde 1 porque el 0 es el x0, o sea el independiente, entonces no hay que evaluarlo
			evaluado+=(v[i]*x);
		}
		return evaluado
	}
	int MostrarSize(){
		return grado;
	};
	int MostrarPoli(int numerito){
		return v[numerito];
	};
	
	
};

vector<int> suma(Polinomio p1, Polinomio p2){
	vector<int> respuesta(max(p1.MostrarSize(),p2.MostrarSize()));
	for (size_t i=0;i<respuesta.size();i++){
		respuesta[i]=p1.MostrarPoli(i)+p2.MostrarPoli(i);
	}
	return respuesta;
}
	
	int main() {
		int grado;
		cout<<"grado del poli: "; cin>>grado;
		grado++;
		Polinomio pol1(grado);
		int coef_a_cambiar, nuevo;
		for (int i=0;i<grado;i++){
			cout<<"ingrese el grado a cambiar y su nuevo valor: "; cin>>coef_a_cambiar>>nuevo;
			pol1.CambiarCoeficiente(coef_a_cambiar,nuevo);
		}
		int valor_x;
		cout<<"valor de x a evaluar: ";cin>>valor_x;
		cout<<"polinomio evaluado en x: "<<pol1.Evaluar(valor_x)<<endl;
		cout<<"polinomio: "<<endl;
		for (int i=pol1.MostrarSize()-1;i>=0;i--){
			if (pol1.MostrarPoli(i)>0){
				cout<<" + "<<pol1.MostrarPoli(i)<<".x"<<i;
			} else if (pol1.MostrarPoli(i)<0){
				cout<<" "<<pol1.MostrarPoli(i)<<".x"<<i;
			} 
			
		}
		
		cout<<endl<<"ingrese el grado del nuevo polinomio: ";cin>>grado;
		grado++;
		Polinomio pol2(grado);
		for (int i=0;i<grado;i++){
			cout<<"ingrese el grado a cambiar y su nuevo valor: "; cin>>coef_a_cambiar>>nuevo;
			pol2.CambiarCoeficiente(coef_a_cambiar,nuevo);
		}
		cout<<"polinomio: "<<endl;
		for (int i=pol2.MostrarSize()-1;i>=0;i--){
			if (pol2.MostrarPoli(i)>0){
				cout<<" + "<<pol2.MostrarPoli(i)<<".x"<<i;
			} else if (pol2.MostrarPoli(i)<0){
				cout<<" "<<pol2.MostrarPoli(i)<<".x"<<i;
			}
		}
		cout<<endl;
		vector<int> resultado=suma(pol1,pol2);
		cout<<"polinomio nuevo: "<<endl;
		for (int i=resultado.size()-1;i>=0;i--){
			if (resultado[i]>0){
				cout<<" + "<<resultado[i]<<".x"<<i;
			} else if (resultado[i]<0){
				cout<<" "<<resultado[i]<<".x"<<i;
			} 
		}
		
		
		
		return 0;
	}
	
