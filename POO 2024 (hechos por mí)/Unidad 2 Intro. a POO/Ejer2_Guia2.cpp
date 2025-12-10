#include <iostream>
#include <cmath>
using namespace std;

class EcuacionCuadratica {
public:
	void Cargar (float a, float b, float c){
		m_a = a;
		m_b = b;
		m_c = c;
		Calcular();
	}

	void Calcular() {
		float discriminante = m_b * m_b - 4.0 * m_a * m_c;
		if (discriminante > 0){
			r_reales = true;
			r_1 = (-m_b + sqrt(discriminante)) / (2 * m_a);
			r_2 = (-m_b - sqrt(discriminante)) / (2 * m_a);
		} else {
			r_reales = false;
			r_1 = -m_b/(2*m_a);
			r_2 = sqrt(-discriminante)/ (2 * m_a);
		}
	}
	
	bool TieneRaicesReales () {return r_reales;}
	float VerRaiz1 () {return r_1;}
	float VerRaiz2 () {return r_2;}
	float VerParteReal () {return r_1;}
	float VerParteImag () {return r_2;}
	
	
private:
	float m_a, m_b, m_c, r_1, r_2;
	bool r_reales;
};


int main() {
	
	EcuacionCuadratica ecu1;
	float a, b ,c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	ecu1.Cargar(a,b,c);
	
	if(ecu1.TieneRaicesReales()){
		cout<<"r1 = "<<ecu1.VerRaiz1()<<endl;
		cout<<"r2 = "<<ecu1.VerRaiz2()<<endl;}
	else{
		cout<<"r1 = "<<ecu1.VerParteReal()<<" + "<<ecu1.VerParteImag()<<"i"<<endl;
		cout<<"r2 = "<<ecu1.VerParteReal()<<" - "<<ecu1.VerParteImag()<<"i"<<endl;
	}
	
	return 0;
}

