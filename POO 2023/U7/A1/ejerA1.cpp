///Diseñe e implemente una clase templatizada llamada Rect que permita representar
///un rectángulo. La clase debe poseer métodos para obtener el alto y ancho del
///rectángulo. Implemente los métodos que considere necesarios para la inicialización
///o carga de datos. Cree un programa cliente que instancie un rectángulo cuyas
///coordenadas sean enteros y otro cuyas coordenadas sean de tipo double

#include <iostream>
using namespace std;

template<typename T>
class Rect{
private:
	T m_alto; T m_ancho;
public:
	Rect(int altura, int anchura){
		m_alto= altura;
		m_ancho= anchura;
	}
};

int main() {

	cout<<"Rectangulo int"<<endl;	
	cout<<"Altura: ";int ali;cin>>ali;
	cout<<"Anchura: ";int ani;cin>>ani;
	
	Rect ent(ali, ani);
	
	cout<<"Rectangulo float"<<endl;
 	cout<<"Altura: ";float alf;cin>>alf;
	cout<<"Anchura: ";float anf;cin>>anf;
	
	Rect fl(alf,anf);
	
	return 0;
}

