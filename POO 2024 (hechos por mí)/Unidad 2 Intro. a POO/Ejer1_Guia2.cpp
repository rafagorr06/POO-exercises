#include <iostream>
using namespace std;

class Cilindro {
private:
	float r, alt, vol;
public:
	void AsignarDatos (float radio, float altura){
		r = radio;
		alt = altura;
	}
	
	float ObtenerVolumen (){
		vol = 3.14 * r * r * alt;
		return vol;
	}
};


int main() {
	Cilindro c1, c2;
	cout << "Ingrese los datos del cilindro: "<<endl;
	float rad, alt;
	cin >> rad;
	cin >> alt;
	c1.AsignarDatos(rad,alt);
	c2.AsignarDatos(5.3,10.2);
	
	cout << "Vol Cilindro 1: " << c1.ObtenerVolumen()<<endl;
	cout << "Vol Cilindro 2: " << c2.ObtenerVolumen()<<endl;
	
	return 0;
}

