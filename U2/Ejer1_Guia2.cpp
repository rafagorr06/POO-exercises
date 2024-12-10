#include <iostream>
using namespace std;

	class Cilindro{
	private:
		float m_radio; float m_altura;
	public:
		Cilindro(float m_r,float m_a){
			m_radio = m_r;
			m_altura = m_a;
		}
		float ObtenerVolumen(){
			float v;
			v = 3.14*m_radio*m_radio*m_altura;
			return v;
		}
	};

int main() {
		float radio, altura;
		
		cout<<"Radio: ";cin>>radio;
		cout<<"Altura: ";cin>>altura;
		
		Cilindro c1(radio,altura);
		cout<<"El volumen del Cilindro c1 es de: "<<c1.ObtenerVolumen();
		cout<<endl;

		Cilindro c2(5.3,10.2);
		cout<<"El volumen del Cilindro c2 es de: "<<c2.ObtenerVolumen();
		
	return 0;
}

