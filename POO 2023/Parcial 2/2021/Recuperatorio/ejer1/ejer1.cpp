#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//template<typename T>
void reordenar(string nombre, int pos1, int pos2){
	ifstream archiin(nombre,ios::binary);
	vector<float>data;
	float valor;
	while(archiin>>valor){
		archiin>>valor;
		data.push_back(valor);
	}
	archiin.close();
	
	auto itp1= data.begin()+pos1;
	auto itp2= data.begin()+pos2;
	
	sort(data.begin(),itp1);
	sort(itp2,data.end());
	reverse(itp2,data.end());
	
	ofstream archiout(nombre,ios::binary);
	for(auto x : data){
		archiout<<x<<endl;
	}
	archiout.close();
}

int main() {
	
	vector<float>valores(21);
	for(int i=1;i<valores.size();++i){
		valores[i]= (10.0 + rand());
	}
	
	for(int i=1;i<valores.size();++i){
		cout<<"Valor "<<i<<": "<<valores[i]<<endl;
	}
	cout<<endl;
	
	cout<<"Nombre del archivo donde quiere la info: ";string nom;cin>>nom;
	
	ofstream archiout(nom,ios::binary);
	for(auto x : valores){
		archiout<<x<<endl;
	}
	archiout.close();
	
	cout<<"Pos 1: ";int pos1;cin>>pos1;
	cout<<"Pos 2: ";int pos2;cin>>pos2;
	
	reordenar(nom,pos1,pos2);
	
	return 0;
}

