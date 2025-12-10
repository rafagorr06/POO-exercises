#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct medalla{int oro,plata,bronce;string pais;};

void agregardato(vector<medalla >info, medalla p1, medalla p2, medalla p3){
	info.push_back(p1);
	info.push_back(p2);
	info.push_back(p3);
	
	ofstream archiout("medalla.txt",ios::trunc);
	for(int i=0;i<info.size();i++){
		archiout<<"NUEVA COMPETENCIA"<<endl;
		archiout<<"El pais: "<<info[i].pais<<" tiene "<<info[i].oro<<" medallas de oro, "<<info[i].plata<<" de plata y, "<<info[i].bronce<<" de bronce"<<endl;
		archiout<<endl;
	}
}

int main() {
	
	ifstream archi("medalla.txt");
	
	vector<medalla>info;
	medalla aux;
	
	while(archi>>aux.oro and archi>>aux.plata and archi>>aux.bronce 
		  and getline(archi,aux.pais)){
		info.push_back(aux);
	}
	archi.close();
	
	medalla pais1;
	medalla pais2;
	medalla pais3;
	
	cout<<"Nombre: ";cin>>pais1.pais;
	cout<<"Oro: ";cin>>pais1.oro;
	cout<<"Plata: ";cin>>pais1.plata;
	cout<<"Bronce: ";cin>>pais1.bronce;
	cout<<endl;
	
	cout<<"Nombre: ";cin>>pais2.pais;
	cout<<"Oro: ";cin>>pais2.oro;
	cout<<"Plata: ";cin>>pais2.plata;
	cout<<"Bronce: ";cin>>pais2.bronce;
	cout<<endl;
	
	cout<<"Nombre: ";cin>>pais3.pais;
	cout<<"Oro: ";cin>>pais3.oro;
	cout<<"Plata: ";cin>>pais3.plata;
	cout<<"Bronce: ";cin>>pais3.bronce;
	cout<<endl;
	
	return 0;
}

