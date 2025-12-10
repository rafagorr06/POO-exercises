#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream archivo("palabras.txt");
	vector<string>v; string s; int c=0;
	if(!archivo.is_open()) throw runtime_error("Error abriendo palabras.txt");
	while (getline(archivo,s)){
		v.push_back(s);
		c++;
	}
	cout<<"Palabras Leídas: " << c << endl;
	sort(v.begin(),v.end());
	for(string s:v){
		cout<<s<<endl;
	}
	archivo.close();
	ofstream archivo2("palabras.txt",ios::trunc);
	for(string s:v){
		archivo2<<s<<endl;
	}
	return 0;
}

