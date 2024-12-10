#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct User{int cod; char nom, pass;};

int main() {
	
	ifstream archi_in("passlist.dat",ios::binary);
	
	vector<User>info;
	
	User aux1;
	
	while(archi_in.read(reinterpret_cast<char*>(aux1.cod),sizeof(int)) and 
		  archi_in.read(reinterpret_cast<char*>(aux1.nom),sizeof(char)) and
		  archi_in.read(reinterpret_cast<char*>(aux1.pass),sizeof(char))){
		info.push_back(aux1);
	}
	
	
	
	return 0;
}

