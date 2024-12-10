#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

struct Detalle {
	int fecha, dni, cod_prod, cant;
};

struct Producto {
	int cod, stock, precio;
	char descripcion[60];
};

void actualizar(int dni, int fecha, vector<int> vcod,
				vector<int> vcant) 
{
	ofstream ventas("ventas.dat",ios::binary|ios::app);
	Detalle det; det.dni = dni; det.fecha = fecha;
	for (size_t i=0; i<vcod.size(); ++i) { 
		det.cod_prod = vcod[i]; det.cant = vcant[i];
		ventas.write(reinterpret_cast<char*>(&det),sizeof(det));
	}
	ventas.close();
	
	fstream productos("productos.dat",ios::binary|ios::in|ios::out|ios::ate);
	int n = productos.tellg()/sizeof(Producto);
	map<int,Producto> m;
	productos.seekg(0);
	for (size_t i=0; i<n; ++i) {
		Producto p;
		productos.read(reinterpret_cast<char*>(&p),sizeof(p));
		m[p.cod] = p;
	}
	
	for (size_t i=0; i<vcod.size(); ++i)
		m[vcod[i]].stock -= vcant[i];
	
	productos.seekp(0);
	for(auto &p : m)
		productos.write(reinterpret_cast<char*>(&p.second),
						sizeof(p.second));
	
}

