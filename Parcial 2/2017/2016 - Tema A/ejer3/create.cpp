#include <fstream>
#include <iostream>
using namespace std;

struct Ficha {
  bool borrado;
  int dni;
  char nombre[50];
  float h;
};

int main(int argc, char *argv[]) {
  fstream file("fichas.dat", ios::binary | ios::in | ios::out | ios::trunc);

  Ficha borr;
  borr.borrado = true;
  borr.dni = 41611198;
  string n = "Franco";
  strcpy(borr.nombre, n.c_str());
  borr.h = 1.71;

  Ficha no_borr;
  no_borr.borrado = false;
  no_borr.dni = 41979987;
  string m = "Alondra";
  strcpy(no_borr.nombre, m.c_str());
  no_borr.h = 1.71;

  file.write((char *)&borr, sizeof(borr));
  file.write((char *)&no_borr, sizeof(no_borr));

  borr.dni = 31611187;
  file.write((char *)&borr, sizeof(borr));
  borr.dni = 37611187;
  file.write((char *)&borr, sizeof(borr));

  no_borr.dni = 29123765;
  file.write((char *)&no_borr, sizeof(no_borr));
  no_borr.dni = 45398888;
  file.write((char *)&no_borr, sizeof(no_borr));
  no_borr.dni = 17277776;
  file.write((char *)&no_borr, sizeof(no_borr));

  borr.dni = 13631258;
  file.write((char *)&borr, sizeof(borr));
  borr.dni = 32979987;
  file.write((char *)&borr, sizeof(borr));

  int cant = file.tellp() / sizeof(Ficha);

  Ficha aux;
  for (int i = 0; i < cant; i++) {
    file.seekg(i * sizeof(Ficha));
    file.read((char *)&aux, sizeof(aux));
    cout << "Nombre: " << aux.nombre << ". DNI: " << aux.dni
         << ". Borrado: " << aux.borrado << endl;
  }

  return 0;
}
