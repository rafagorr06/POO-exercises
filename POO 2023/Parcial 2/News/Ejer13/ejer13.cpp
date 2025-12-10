#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

class ManejaddorDeTexto{
private:
	vector<string>datos;
public:
	void ManejadorDeTexto(string nombrearchi){
		
		ifstream archi(nombrearchi);
		string data;
		
		while(archi>>data){
			datos.push_back(data);
		}
		archi.close();
	}
	void reemplazar(string valor, string cambiar){
		for(int i=0;i<datos.size();i++){
			if(datos[i] == valor){
				datos[i] = cambiar;
			}
		}
	}
	void guardardatos(string newnombre){
		
		ofstream archiout(newnombre);
		for(int i=0;i<datos.size();i++){
			archiout<<datos[i]<<endl;
		}
	}
	void MayusOrMinus(int n){
		if(n == 1){///minuscula
			for(int i=0;i<datos.size();i++){
				for(auto &x : datos[i]){
					x= tolower(x);	
				}
			}
		}else if(n == 2){///mayuscula	
			for(int i=0;i<datos.size();i++){
				for(auto &x : datos[i]){
					x= toupper(x);	
				}
			}
		}
	}
};

int main() {
	
	return 0;
}

