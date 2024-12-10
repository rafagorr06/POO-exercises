#include <iostream>
using namespace std;

class Triangulo{
private:
	float mt_b; float mt_a;
public:
	Triangulo(float base, float altura){
		mt_b = base;
		mt_a = altura;
	}
	float verAreaT(){
		return ((mt_b*mt_a)/2);
	}
};

class Rectangulo{
private:
	float mr_b; float mr_a;
public:
	Rectangulo(float baser, float alturar){
		mr_b = baser;
		mr_a = alturar;
	}
	float verAreaR(){
		return (mr_b*mr_a);
	}
};

class TrapecioRect{
private:
	Rectangulo r;
	Triangulo t;
public:
	TrapecioRect(float baseREC, float baseTRI, float altura):r(baseREC,altura), t(baseTRI,altura){}
	float VerAreaTR(){
		return ((r.verAreaR())+(t.verAreaT()));
	}
};

int main() {
	
	float baseR; float baseT; float altura;
	cout<<"Datos trapecio"<<endl;
	cout<<"Base Rectangulo: ";cin>>baseR;
	cout<<"Base Triangulo: ";cin>>baseT;
	cout<<"Altura: ";cin>>altura;
	
	cout<<endl;
	
	TrapecioRect tr(baseR,baseT,altura);
	
	cout<<"Area del trapecio: "<<tr.VerAreaTR()<<endl;
	
	return 0;
}

