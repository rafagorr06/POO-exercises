#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Monomio {
public:
	Monomio(int g, float c) : grado(g), coef(c) { }
	float VerCoef() { return coef; }
	float Evaluar(float x) {
		return coef*pow(x,grado);
	}
private:
	int grado;
	float coef;
};

class Polinomio { 
public:
	Polinomio(int grado) : vmon(grado+1,Monomio(0,0)) { }
	int VerGrado() { return vmon.size()-1; }
	void CargarCoef(int grado, float coef) { vmon[grado] = Monomio(grado,coef); }
	float VerCoef(int grado) { return vmon[grado].VerCoef(); }
	float Evaluar(float x) {
		float s = 0;
		for(Monomio m : vmon)
			s += m.Evaluar(x);
		return s;
	}
private:
	vector<Monomio> vmon;
};

/** Para referencia, este era el polinomio de la guia anterior

class Polinomio {
public:
	Polinomio(int grado) : vcoefs(grado+1,0) { }
	int VerGrado() { return vcoefs.size()-1; }
	void CargarCoef(int grado, float coef) { vcoefs[grado] = coef;	}
	float VerCoef(int grado) { return vcoefs[grado]; }
	float Evaluar(float x) {
		float x = 0;
		for (int g=0; g<=grado; ++g) 
			x += vcoefs[g]*pow(x,g);
		return x;
	}
private:
	vector<float> vcoefs;
};

**/

int main() {
	
	return 0;
}

