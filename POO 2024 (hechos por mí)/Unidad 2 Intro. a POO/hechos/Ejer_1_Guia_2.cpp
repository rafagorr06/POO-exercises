#include <iostream>

using namespace std;



class Cilindro {
	public:
		void AsignarDatos(float rad, float alt){
			m_radio=rad;m_altura=alt;
		}
		float ObtenerVolumen(){
			return m_radio*m_radio*m_altura*3.14;
		}
	private: 
		float m_radio; float m_altura;
};



int main() {
	
	Cilindro c1, c2;
	
	c2.AsignarDatos(5.3,10.2);
	float rad, alt;
	cout<<"Ingrese el Radio y Altura"<<endl;
	cin>>rad>>alt;
	c1.AsignarDatos(rad,alt);
	cout<<"Volumen cilindro 1" <<c1.ObtenerVolumen()<<endl;
	cout<<"Volumen cilindro 2" <<c2.ObtenerVolumen()<<endl;
	return 0;
}

