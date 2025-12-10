#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	ifstream archi_in("listastr.txt");
	
	vector<string>datos;
	string data;
	
	while(getline(archi_in,data)){///C
		auto pos1= data.find(" ");
		auto pos2= data.find_last_of(" ");
		data.erase(pos1+1,pos2);
		datos.push_back(data);
	}
	archi_in.close();
	
	sort(datos.begin(),datos.end());
	
	unique(datos.begin(),datos.end());///B
	
	sort(datos.begin()+3,datos.end());///D
	
	ofstream archi_out("listasrt.txt",ios::trunc);
	
	for(int i=0;i<datos.size();i++){///E
		archi_out<<datos[i]<<endl;
	}
	archi_out.close();
	
	return 0;
}

