#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Alumno {
	string nombre;
	float nota;
};

class Cusrso {
public:
	void CargarAlumno (string nombrealu) {
		clase.push_back(nombrealu);
	}
	
	void ModificarNota (string nombrealu, float calif){
		for(int i=0;i<salon.size;i++) { 
			if (salon[i].nombre=nombrealu) {
				salon[i].nota=calif;
			}
		}
	}
		
private:
	int n;
	float calif;
	string nombrealu;
	vector<Alumno>salon;
};
int main() {
	
	return 0;
}

