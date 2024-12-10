#include <iostream>
#include <list>
using namespace std;

template<typename T>
T mas_repetido(const list<T>&L){
	int may=0;
	T val_may;
	for(T x : L){
		int n= count(L.begin(),L.end(),x);
		if(n>may){
			may= n;
			val_may= x;
		}
	}
	return x;
}
struct Ficha { int dni; string ape, nom;};
	
bool operator==(Ficha f1, Ficha f2) {	return f1.dni == f2.dni;
}

int main() {
	
	list<string>ls;
	string s;
	getline(cin,s);
	
	while(not s.empty()) {
		ls.push_back(s);
		getline(cin,s);
	}
	
	string ms = mas_repetido(ls);
	cout<<"Más repetido: "<<ms<<endl;
	
	list<int> li(50);
	for(int &x : li) x = rand()%100+100;
	int mi = mas_repetido(li);
	cout<<"Más repetido: "<<mi<<endl;
	
	
	ifstream archi("lista.txt");
	Ficha f;
	while (archi>>f.dni and getline(archi,s)) {
		s.erase(0,1);
		auto p = s.find(',');
		f.ape = s.substr(0,p);
		f.nom = s.substr(p+2);
		lf.push_back(f);
	}
	Ficha mf = mas_repetido(lf);
	cout<<"Más repetido: "<<endl;
	cout<<mf.dni<< " - "<<mf.nom<< " "<<mf.ape<< endl;
	
	
	
	return 0;
}

