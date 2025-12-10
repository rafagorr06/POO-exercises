#include <iostream>
#include <cmath>
using namespace std;

	class Tanque{
	private:
		float m_peso;
	public:
		void AsignarPeso(float p){
			m_peso = p;
		}
		
		virtual float VerVolumen()= 0;
		
		float VerPeso(){
			return m_peso;
		};
		
		virtual ~Tanque(){};
	};

	class Cilindro : public Tanque{
	private:
		float m_radio, m_altura;
	public:
		Cilindro(float radio, float altura, float peso){
			m_radio = radio;
			m_altura = altura;
			AsignarPeso(peso);
		}
		float VerVolumen() override{
			float volc;
			return volc = (3.14*(pow(m_radio,2)))*m_altura;
		}
	};
	
	class Esfera : public Tanque{
	private:
		float m_radioe;
	public:
		Esfera(float radio, float peso){
			m_radioe = radio;
			AsignarPeso(peso);
		}
		float VerVolumen() override{
			float vole;
			return vole = (4.0/3.0)*(3.14*(pow(m_radioe,3)));
		}
	};
int main() {
	
	cout<<"Radio del Cilindro: ";float radioC;cin>>radioC;
	cout<<"Altura del Cilindro: ";float alturaC;cin>>alturaC;
	cout<<"Peso del Cilindro: ";float pesoC;cin>>pesoC;
	cout<<endl;
	
	Tanque *p = new Cilindro(radioC,alturaC,pesoC);
	cout<<"El Cilindro de "<<p->VerPeso()<<"gr, tiene un volumen de: "<<p->VerVolumen()<<".";
	delete p; ///borra contenido dentro de del puntero, no el puntero en si
	
	cout<<endl;cout<<endl;
	
	cout<<"Radio del Esferico: ";float radioE;cin>>radioE;
	cout<<"Peso del Esferico: ";float pesoE;cin>>pesoE;
	cout<<endl;
	
	p = new Esfera(radioE,pesoE);
	cout<<"El Esferico de "<<p->VerPeso()<<"gr, tiene un volumen de: "<<p->VerVolumen()<<".";
	
	delete p;
	return 0;
}

