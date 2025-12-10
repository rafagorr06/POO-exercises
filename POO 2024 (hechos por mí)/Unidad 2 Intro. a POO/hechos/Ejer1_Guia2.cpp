#include <iostream>
using namespace std;


class Cilindro{
private:
	float radio,altura,volumen;	
public:
	cilindro(float r,float alt){
		AsignarDatos(r,alt);
	}
	void AsignarDatos(float r,float alt){
		altura = alt;radio = r;
		volumen = 3.141516 * radio * radio * altura;
	}
	float ObtenerVolumen(){
		return volumen;	
	}		

};
int main() {
	cilindro c1(7,15) ;
	cout<<"el volumen es : "<<c1.ObtenerVolumen()<<endl;
	return 0;
}

