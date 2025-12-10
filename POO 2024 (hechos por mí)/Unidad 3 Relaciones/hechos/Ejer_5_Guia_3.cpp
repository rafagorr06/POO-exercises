#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
	float x;
	float y;
};

class RectaExplicita {
public:
	RectaExplicita(Punto p, Punto q) : p(p),q(p){}
	float verM(){
		float m=(q.y-p.y)/(q.x-p.x); 
		return m;
	};
		
	float verB() {
		float b= (p.y)-(m*p.x);
		return b;
	};
	
	string obtenerEcuacion() {
		string m1 = to_string(m);
		string b1 = to_string(b);	
		return ("y="+m1+"x"+b1);
	};
	
	bool EsIgual (float a, float b){
		return fabs(a-b)<0.00001;
	};
	bool pertenece(Punto p){
		if (){
			return true;
		}
		return false;
	};
	
private:
	float m, b;
	Punto p, q;
	string m1, b1;
};

int main() {
	
	return 0;
}

