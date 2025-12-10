#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

struct par {
	int entero;
	float flotante;
};

int main() {
	//a
	ofstream f("grupo.dat", ios::binary);
	if (!f.is_open()) {throw runtime_error ("error");}
	par aux;
	for(int i=0;i<200;i++) { 
		aux.entero=rand()%100;
		aux.flotante=(rand()%100)/10.0;
		f.write((char*)&aux,sizeof(aux));
		cout<<aux.entero<<" "<<aux.flotante<<endl;
		}
	f.close();
	return 0;
}

