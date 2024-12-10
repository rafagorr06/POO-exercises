#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Pizza {
	string m_tipo; 
public: 
	Pizza(string tipo): m_tipo(tipo){}
	string VerTipo(){return m_tipo;}
	virtual float CalcularCosto(float dolar)=0;
	virtual ~Pizza(){}
};

class Redonda : public Pizza{
	string m_tipo_pizza; 
	float m_radio;
public: 
	Redonda(string tipo, float radio): Pizza(tipo){
		m_tipo_pizza=tipo;
		m_radio=radio;
	}
	float CalcularCosto(float dolar) override{
		float costo=0;
		if (VerTipo()=="Muzza"){
			costo= 1.0*dolar*3.14*pow(m_radio,2)/20;
		}else if(VerTipo()=="Choco"){
			costo= 1.8*dolar*3.14*pow(m_radio,2)/20;
		} else {
			costo= 1.45*dolar*3.14*pow(m_radio,2)/20;
		}
		return costo;
	}
};
class Rectangular : public Pizza {
	string m_tipo_pizza; 
	int m_alto, m_ancho;
public: 
	Rectangular(string tipo, int alto, int ancho): Pizza(tipo){
		m_tipo_pizza=tipo;
		m_ancho=ancho;
		m_alto=alto;
	}
	float CalcularCosto(float dolar) override {
		float costo=0;
		if (VerTipo()=="Muzza"){
			costo= 1.0*dolar*m_ancho*m_alto/16; 
		}else if(VerTipo()=="Choco"){
			costo= 1.8*dolar*m_ancho*m_alto/16; 
		} else {
			costo= 1.45*dolar*m_ancho*m_alto/16; 
		}
		return costo;
	}	
};
float CostoPedido(vector<Pizza*> Pedidos, float dolar){
	float suma=0; 
	for (size_t i=0; i<Pedidos.size(); ++i){
		suma+=Pedidos[i]->CalcularCosto(dolar);
	}
	return suma;
}
int main() {
	
	return 0;
}

