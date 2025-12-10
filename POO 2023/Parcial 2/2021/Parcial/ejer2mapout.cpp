#include <iostream>
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
		det.cod_prod = vcod[i]; v.cant = vcant[i];
		ventas.write(reinterpret_cast<char*>(&det),sizeof(det));
	}
	ventas.close();
	
	fstream productos("productos.dat",ios::binary|ios::in|ios::out|ios::ate);
	int n = productos.tellg()/sizeof(Producto);
	map<int,Producto> v;
	productos.seekg(0);
	for(Producto &p : v)
		productos.read(reinterpret_cast<char*>(&p),sizeof(p));
	
	for (size_t i=0; i<vcod.size(); ++i) { 
		for(Producto &p : v) {
			if (p.cod==vcod[i]) {
				p.stock -= vcant[i];
				break;
			}
		}
	}
	
	productos.seekp(0);
	for(Producto &p : v)
		productos.write(reinterpret_cast<char*>(&p),sizeof(p));
	
	
}

