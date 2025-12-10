#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
class ManejadorArchivo {
public:
	ManejadorArchivo (const string& archivo) : nombrearchivo(archivo) {}
	bool CargarArchivo() {
		ifstream archivo(nombreArchivo, ios::binary);
		if (!archivo) {
			throw runtime_error("Posicion incorrecta");
			return false;
		}
		T registro;
		while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(T))) {
			registros.push_back(registro);
		}
		archivo.close();
		return true;
	}
	T ObtenerRegistro (int pos) {
		if (pos>registros.size()) {
			throw runtime_error("Posicion incorrecta");
		} else {
			return registros[pos];
		}
	}
	void ModificarRegistro (T mod, int pos){
		if (pos>registros.size()) {
			throw runtime_error("Posicion incorrecta");
		} else {
			registros[pos]=mod;
		}
			
	}
	bool ActualizarArchivo() {
		ofstream archivo(nombreArchivo, ios::binary | ios::trunc);
		if (!archivo) {
			throw runtime_error("Posicion incorrecta");
			return false;
		}
			
		for (const auto& registro : registros) {
			archivo.write(reinterpret_cast<const char*>(&registro), sizeof(T));
		}
		archivo.close();
		return true;
	}

private:
	string nombrearchivo;
	vector<T>registros;
};


int main() {
	
	return 0;
}

