#include <iostream>
#include <fstream>
using namespace std;

void mostrar_archivo(const char* nombre_archivo) {
	std::ifstream archivo(nombre_archivo, std::ios::binary);
	
	if (!archivo) {
		std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
		return;
	}
	
	int numero;
	std::cout << "Contenido del archivo " << nombre_archivo << ": ";
	while (archivo.read(reinterpret_cast<char*>(&numero), sizeof(int))) {
		std::cout << numero << " ";
	}
	std::cout << std::endl;
	
	archivo.close();
}
	
int main() {
	ofstream archivo("enteros.bin", ios::binary);
	if (!archivo.is_open()) {throw runtime_error ("error");}
	
	for (int i = 0; i < 100; ++i) {
		int numero = i * 5;
		archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int));
	}
	
	archivo.close();
	

	ifstream archivo_lectura("enteros.bin", std::ios::binary);  
	ofstream archivo_temporal("temp.bin", std::ios::binary);
	
	if (!archivo_lectura || !archivo_temporal) {throw runtime_error ("error");}
	
	int nuevo_numero;
	cout << "Ingrese un nuevo número: ";
	cin >> nuevo_numero;
	
	int numero_actual;
	bool insertado = false;
	
	while (archivo_lectura.read(reinterpret_cast<char*>(&numero_actual), sizeof(int))) {
		if (!insertado && nuevo_numero < numero_actual) {
			archivo_temporal.write(reinterpret_cast<const char*>(&nuevo_numero), sizeof(int));
			insertado = true;
		}
		archivo_temporal.write(reinterpret_cast<const char*>(&numero_actual), sizeof(int));
	}
	
	if (!insertado) {
		archivo_temporal.write(reinterpret_cast<const char*>(&nuevo_numero), sizeof(int));
	}
	
	archivo_lectura.close();
	archivo_temporal.close();
	
	remove("enteros.bin");
	rename("temp.bin", "enteros.bin");
	
	mostrar_archivo("enteros.bin");
	return 0;
}

