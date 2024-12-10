///Un conjunto de archivos de texto contiene información guardada en el formato que
///se muestra en el recuadro, donde cada línea contiene el nombre de un campo y su
///respectivo valor separados por el signo igual (=). Las líneas que comienzan con el
///carácter '#' deben ser ignoradas.///Escriba una clase llamada ConfigFile que permita interpretar el contenido de estos archivos. La clase debe poseer:
///a) un constructor que reciba el nombre del archivo y cargue sus datos en un
///vector de structs (cada elemento es struct con dos strings: campo y valor).
///b) un método para consultar el valor asociado a un campo
///c) un método para modificar el valor asociado a un campo
///d) un método para guardar el archivo con los datos actualizados	
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct CV{string campo,valor;};

class ConfgFile{
private:
	vector<CV>datos;
	string nombrearchi;
public:
	ConfgFile(string ruta) : nombrearchi(ruta){		///A
	ifstream archiCF(ruta);
	if(!archiCF.is_open()){ return; }     			///al estar en constructor no retorno nada
	
	string linea;									///que debe leer
	while(getline(archiCF,linea)){
		if(linea.empty() or linea[0]== '#'){continue;} ///si la linea esta vacia o empieza con #, continua
		int pos= linea.find('=');					///busco la posicion del divisor (=)
		if(pos == string::npos){continue;}			
		CV p;
		p.campo= linea.substr(0,pos);				///de la linea sacamos desde cero hasta pos(=)
		p.valor= linea.substr(pos+1);				///sacamos desde pos(=) + 1 hasta el final
		datos.push_back(p);
	}		
	}
	string VerValor(string campoV){					///B
		for(auto &x : datos){
			if(x.campo == campoV){
				return x.valor;
			}
		}
		return "**";
	}
	void ModificarValor(string campoM, string valorM){
		for(auto &x : datos){
			if(x.campo == campoM){
				x.valor = valorM;
				return;
			}
		}
		datos.push_back({campoM,valorM});
	}
	void GuardarDatos(){
		ofstream archiCambios("NewCV.txt");
		for(auto &x : datos){
			archiCambios<<x.campo<<" = "<<x.valor<<endl;
		}
///		for(int i=0;i<datos.size();i++){
///			archiCambios<<datos[i].campo<<" = "<<datos[i].valor<<endl;
///		}
		archiCambios.close();
	}
};

int main() {
	ConfgFile C("CV.txt");
	
	cout<<"Ingrese el campo a ver: ";string campo;cin>>campo;
	if(C.VerValor(campo) =="**"){
		cout<<"Campo incorrecto"<<endl;
	}
	else{ cout<<"Valor: "<<C.VerValor(campo)<<endl;}
	
	cout<<endl;
	
	cout<<"Campo que quiere modificar: ";string campoM;cin>>campoM;
	cin.ignore();
	cout<<"Nuevo valor a colocar: ";string valorM;getline(cin,valorM);
	
	C.ModificarValor(campoM,valorM);
	C.GuardarDatos();
	return 0;
}
