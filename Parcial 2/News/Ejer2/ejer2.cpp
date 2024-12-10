#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	
	ifstream archid("discurso.txt");
	vector<string>frases;
	string palabra;
	
	while(getline(archid,palabra)){
		archid>>palabra;
		frases.push_back(palabra);
		archid.ignore();
	}
	archid.close();
	
	vector<string>palabrotas;
	ifstream archip("palabrotas.txt");
	while(archip>>palabra){
		archip>>palabra;
		palabrotas.push_back(palabra);
	}
	archip.close();
	
	for(int i=0;i<frases.size();i++){
		for(int j=0;i<palabrotas.size();i++){
			if(frases[i] == palabrotas[j]){
				frases[i]= "**beep**";
			}
		}
	}
	
	ofstream archio("discurso.txt",ios::trunc);
	for(int i=0;i<frases.size();i++){
		archio<<frases[i];
	}

	
	return 0;
}
