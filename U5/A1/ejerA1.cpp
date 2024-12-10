#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream archiDQ("DonQuijote.txt");
	if(!archiDQ.is_open()){
		cerr<<"No se abrio el archivo"<<endl;
		return 1;
	}
	
	vector<string>text;
	string frase;
	
	while(getline(archiDQ,frase)){
		archiDQ>>frase;
		text.push_back(frase);
		archiDQ.ignore();
	}
	archiDQ.close();
	
	cout<<"Frase a buscar: ";string mdv;getline(cin,mdv);
	int contador=0;
	
	for(int i=0;i<text.size();++i){
		if(text[i] == mdv){++contador;}
	}

	cout<<"Molinos de viento aparece: "<<contador<<" veces"<<endl;
	return 0;
}

