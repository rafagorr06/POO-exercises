#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class Tecla{
private:
	string m_nota;
	bool presionada;
public:
	Tecla(string nota):m_nota(nota), presionada(false){}
	
	string VerNota(){
		return m_nota;
	};
	void Apretar(){
		presionada = true;
	}
	void Soltar(){
		presionada = false;
	}
	bool EstaApretada(){
		return presionada;
	}
};

class Pedal{
private:
	float m_presion;
public:
	Pedal():m_presion(0){}
	
	void Presionar(float p){
		m_presion = p;
	}
	float VerPresion(){
		return m_presion;
	}
};

class Instrumento{
public:
	virtual string VerTipo(){
		return "sin_nombre";
	}
};

class Piano: public Instrumento{
private:
	vector<Tecla> t;
	Pedal pe;
public:
	Piano(){
		t.push_back(Tecla("do"));
		t.push_back(Tecla("re"));
		t.push_back(Tecla("mi"));
		t.push_back(Tecla("fa"));
		t.push_back(Tecla("sol"));
		t.push_back(Tecla("la"));
		t.push_back(Tecla("si"));
	}
	string VerTipo() override{
		return "Piano";
	}
	string ApretarTecla(int x){
		t[x].Apretar();
		return t[x].VerNota();
	}
	string SoltarTecla(int x){
		t[x].Soltar();
		return t[x].VerNota();
	}
	float PresionarPedal(float p){
		pe.Presionar(p);
		return pe.VerPresion();
	}
};
int main() {
	
	return 0;
}

