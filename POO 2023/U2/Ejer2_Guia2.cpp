#include <iostream>
#include <cmath>
using namespace std;

	class EcuacionCuadratica{
	private:
		float m_a; float m_b; float m_c;
	public:
		EcuacionCuadratica(float a, float b, float c){
			m_a = a;
			m_b = b;
			m_c = c;
		}
		bool TieneRaicesReales(){
			float discriminante = ((m_b*m_b)-(4*m_a*m_c));
			if(discriminante >=0){
				return true;
			}
			else {return false;}
		}
		float VerRaiz1(){
			float r1 = ((-m_b)+sqrt((m_b*m_b)-(4*m_a*m_c)))/(2*m_a);
			return r1;
		}
		float VerRaiz2(){
			float r2 = ((-m_b)-sqrt((m_b*m_b)-(4*m_a*m_c)))/(2*m_a);
			return r2;
			}
	};

int main() {
	
		float a2,b2,c2;
		cout<<"Coeficiente A: ";cin>>a2;
		cout<<"Coeficiente B: ";cin>>b2;
		cout<<"Coeficiente C: ";cin>>c2;
		cout<<endl;
		
		cout<<"Su función es: "<<a2<<"^2"<<"x"<<b2<<"x"<<c2;
		EcuacionCuadratica c1(a2,b2,c2);
		cout<<endl;
		
		if(c1.TieneRaicesReales() > 0){
			cout<<"Tiene 1 o más raices reales"<<endl;
		}
		else cout<<"No tiene raices reales"<<endl;
		cout<<endl;
		
		if(c1.TieneRaicesReales() > 0){
			cout<<"Raiz 1: "<<c1.VerRaiz1();
			cout<<endl;
			cout<<"Raiz 2: "<<c1.VerRaiz2();
		}
		
	return 0;
}

