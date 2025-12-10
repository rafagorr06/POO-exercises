#include <iostream>
using namespace std;

class Rectangulo{
private:
	float m_base; float m_altura;
public:
	Rectangulo(float base, float altura){
		m_base = base;
		m_altura = altura;
	}
	float VerArea(){
		return m_base*m_altura;
	}
	float VerPerimetro(){
		return ((2*m_base)+(2*m_altura));
	}
	bool EsCuadrado(){
		if(m_base == m_altura){
			return true;
		}
		else return false;
	}
};
int main() {
	
	cout<<"Base del Rectangulo: ";float base;cin>>base;
	cout<<"Altura del Rectangulo: ";float altura;cin>>altura;
	Rectangulo r(base,altura);
	
	cout<<endl;
	
	cout<<"Area: "<<r.VerArea()<<endl;
	cout<<"Perimetro: "<<r.VerPerimetro()<<endl;
	
	cout<<endl;
	
	if(r.EsCuadrado() == true){
		cout<<"El Rectangulo es cuadrado"<<endl;
	}
	else cout<<"El Rectangulo es cuadrado"<<endl;
	
	return 0;
}

