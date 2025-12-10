#include <iostream>
using namespace std;

class Fraccion{
private:
	int m_num; int m_den;
public:
	Fraccion(int num, int den){
		m_num = num;
		m_den = den;
	}
	int VerNum(){
		return m_num;
	}
	int VerDen(){
		return m_den;
	}
	double convertirADoble(){
		return (double)m_num/(double)m_den;
	}
};

class NumeroMixto{
private:
	int m_entero;
	Fraccion impropia;
public:
	NumeroMixto(int entero, int numerador, int denominador):impropia(numerador,denominador){
		m_entero = entero;
	}
	int VerEntero(){
		return m_entero;
	}
	int VerNumImp(){
		return impropia.VerNum();
	}
	int VerDenImp(){
		return impropia.VerDen();
	}
	double convertirADobleImp(){
		return (m_entero+impropia.convertirADoble());
	}	
};

int main() {
	
	NumeroMixto n(2,1,4);
	cout<<"Entero: "<<n.VerEntero()<<endl;
	cout<<"Numerador: "<<n.VerNumImp()<<endl;
	cout<<"Denominador: "<<n.VerDenImp()<<endl;
	
	cout<<endl;
	
	cout<<"Decimal: "<<n.convertirADobleImp()<<endl;
	return 0;
}

