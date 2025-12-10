#include <iostream>
	using namespace std;
	
	class Tanque {
	public:
		Tanque(int peso) : t_peso(peso) {}
		virtual ~Tanque(){};
		int consultarPeso() { return t_peso; }
		virtual int volumen() = 0;
		
	protected:
		int t_peso;
	};
	
	class Cilindro : public Tanque {
	public:
		Cilindro(int radio, int altura, int peso) : Tanque(peso), m_radio(radio), m_altura(altura) {}
		~Cilindro(){};
		int volumen() override {
			return (m_radio * m_radio * 3.1416 * m_altura);
		}
		
	private:
		int m_radio, m_altura;
	};
	
	class Esfera : public Tanque {
	public:
		Esfera(int radio, int peso) : Tanque(peso), m_radio(radio) {}
		~Esfera(){};
		int volumen() {
			return (4.0/3) * 3.1416 * m_radio * m_radio * m_radio;
		}
		
	private:
		int m_radio;
	};
	
	int main() {
		Tanque* tanque = nullptr;
		
		tanque = new Cilindro(3, 5, 10);
		cout << "Volumen del cilindro: " << tanque->volumen() << " m3" << endl;
		delete tanque;

		tanque = new Esfera(4, 8);
		cout << "Volumen de la esfera: " << tanque->volumen() << " m3" << endl;
		delete tanque;
		
		return 0;
	}

