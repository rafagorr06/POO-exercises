/*
a) Diseñe una clase para representar un viaje que guarde y permita consultar la 
siguiente información: ciudades de origen y destino, medio de transporte 
(un string, por ej "avión”), y distancia (en kms).
b) Implemente 3 clases que representen viajes en tres medios de transportes 
específicos: en avión, en auto y en colectivo.
Cada una de estas clases debe permitir obtener el tiempo del viaje de la siguiente forma:
- en auto: t = distancia/110 + .5*(distancia%110) // se viaja a 110km/h, con un descanso de 30m cada 2h
- en avión: t = 2+distancia/900 // se viaja a 900km/h, pero hay que estar 2 horas antes en el aeropuerto
- en colectivo: t = distancia/90 // se viaja a 90km/h, sin esperas antes ni paradas
c) Implemente una función que reciba un vector de viajes y retorne el tiempo total (la suma).
d) Escriba un programa cliente que genere un vector con 3 viajes: de Rosario a 
Paraná en auto (200km), de Paraná a Buenos Aires en avión (400km), y de Buenos 
Aires a Rosario en colectivo (320km). El programa debe usar la función para obtener
y luego mostrar el tiempo total.
*/
#include <iostream>
#include <vector>
using namespace std;
class Viaje{
	string CiudadDeOrigen="sn";
	string Destino="sn";
	string Transporte="sn";
	float distancia=0;
public:
	Viaje(string CDO, string D, string T, float km) : CiudadDeOrigen(CDO),Destino(D),Transporte(T), distancia(km){}
	string VerCiudadOrigen(){ return CiudadDeOrigen; }
	string VerDestino() { return Destino; }
	string VerTransporte() { return Transporte; }
	virtual float CalcularTiempo()=0;
};
class ViajeAuto : public Viaje{
	int distancia;
public:
	ViajeAuto(string origen, string destino, float km) : Viaje(origen, destino,"Auto", km),distancia(km){}
	float CalcularTiempo() override{
		return (distancia/110 + 0.5*(distancia/110));
	};
};
class ViajeAvion : public Viaje{
	float distancia;
public:
	ViajeAvion(string origen, string destino, float km) : Viaje(origen, destino,"Avión", km),distancia(km){}
	float CalcularTiempo() override{
		return (2+distancia/900);
	};
};
class ViajeCole : public Viaje{
	float distancia;
public:
	ViajeCole(string origen, string destino, float km) : Viaje(origen, destino,"Colectivo", km),distancia(km){}
	float CalcularTiempo() override{
		return (distancia/90);
	};
};
float TiempoTotal(vector<Viaje*> v){
	float sumatotal = 0;
	for(int i=0;i<3;++i) { 
		sumatotal = v[i]->CalcularTiempo() + sumatotal;
	}
	return sumatotal;
}
int main() {
	/*d) Escriba un programa cliente que genere un vector con 3 viajes: de Rosario a 
	Paraná en auto (200km), de Paraná a Buenos Aires en avión (400km), y de Buenos 
	Aires a Rosario en colectivo (320km). El programa debe usar la función para obtener
	y luego mostrar el tiempo total.*/
	Viaje* v1 = new ViajeAuto("Rosario","Paraná",200);
	Viaje* v2 = new ViajeAvion("Paraná","Buenos Aires",400);
	Viaje* v3 = new ViajeCole("Buenos Aires","Rosario",320);
	vector<Viaje*> Viajazo={v1,v2,v3};
	cout<<"El tiempo total del viaje fue de: "<<TiempoTotal(Viajazo)<<"hs."<<endl;
	return 0;
}

