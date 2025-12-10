///Escriba un programa abra el archivo generado en el ejercicio anterior y solicite al
///usuario que ingrese un entero, un flotante y una posición. El programa debe
///sobrescribir el par en la posición ingresada por el usuario por el nuevo par. Luego
///muestre la lista de datos en consola mostrando un par por línea

#include <iostream>
#include <fstream>
using namespace std;

struct Par{int ent; float flot;};
	
int main() {
	
	fstream archi_I("grupo.dat",ios::binary|ios::in|ios::out);	///abor para lectura y escritura

	cout<<"Entero: ";int entero;cin>>entero;
	cout<<"Flotante: ";float flotante;cin>>flotante;
	cout<<"Pos: ";int pos;cin>>pos;
	
	Par p; p.ent=entero; p.flot=flotante;	///Creo el par
	
	archi_I.seekp(sizeof(p)*pos);	///Cambiar pos a la posicion de pos, y cant de bytes
	archi_I.write(reinterpret_cast<char*>(&p),sizeof(p)); ///escribo en el archi_I
	
	for(int i=0;i<200;i++){
		Par aux;	///Por cada for, un nuevo Par
		archi_I.read(reinterpret_cast<char*>(&aux),sizeof(aux));	///leo el archi_I
		cout<<"Posicion: "<<i;
		cout<<" Entero: "<<aux.ent<<" Flotante: "<<aux.flot<<endl;	///lo muestro en pantalla
	}
	archi_I.close();
	
	return 0;
}

