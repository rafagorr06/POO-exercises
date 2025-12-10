#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Ficha {
  bool borrado;
  int dni;
  char nombre[50];
  float h;
};

bool ficha_decreciente(Ficha a, Ficha b) {
  if (a.dni < b.dni)
    return false;
  else
    return true;
}

int main(int argc, char *argv[]) {
  ifstream file("./fichas.dat", ios::binary | ios::ate);
  list<Ficha> fichas;
  int cant = file.tellg() / sizeof(Ficha);

  Ficha aux;
  for (int i = 0; i < cant; i++) {
    file.seekg(i * sizeof(Ficha));
    file.read((char *)&aux, sizeof(aux));
    if (!aux.borrado) {
      fichas.push_back(aux);
    }
  }
  file.close();

  fichas.sort(ficha_decreciente);

  ofstream file_out("./fichas.dat", ios::binary | ios::trunc);

  for (Ficha ficha : fichas) {
    cout << "Nombre: " << ficha.nombre << ". DNI: " << ficha.dni
         << ". Borrado: " << ficha.borrado << endl;
    file_out.write((char *)&ficha, sizeof(ficha));
  }

  file_out.close();

  return 0;
}
