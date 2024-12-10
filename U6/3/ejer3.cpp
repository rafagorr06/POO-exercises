#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int cont=5;
	ofstream archi("ej6.poo",ios::binary|ios::out);
	for(int i=0;i<100;i++) { 
		archi.write(reinterpret_cast<char*>(&cont),sizeof(cont));
		cont+=5;	///Crear el archivo para datos de 5 en 5
	}
	archi.close();
	
	cout<<"Ingrese un entero: ";int a;cin>>a;
	
	fstream archi2("ej6.poo",ios::binary|ios::ate|ios::in|ios::out);	///abro el archi, que se ubica al final, para lec y escri
	
	int n=(archi2.tellp()/sizeof(a));	///n es el tamaño de archi/el tamaño de a(entero)
	archi2.seekg(0);	///cambio la pos a cero
	
	int pos;
	for(int i=0;i<n;i++) { 
		archi2.read(reinterpret_cast<char*>(&cont),sizeof(cont));
		if(cont>a){
			pos=i; break;
		}
		if(i==(n-1)){
			pos=n;
		}
	}
	for(int i=n;i>pos;i--) { 
		archi2.seekp((i-1)*sizeof(int));
		archi2.read(reinterpret_cast<char*>(&cont),sizeof(cont));
		archi2.write(reinterpret_cast<char*>(&cont),sizeof(cont));
	}
	archi2.seekg((pos)*sizeof(int));
	archi2.write(reinterpret_cast<char*>(&a),sizeof(a));
	archi2.seekg(0);
	for(int i=0;i<n+1;i++) { 
		archi2.read(reinterpret_cast<char*>(&cont),sizeof(cont));
		cout << cont << endl;
	}
	return 0;
}

