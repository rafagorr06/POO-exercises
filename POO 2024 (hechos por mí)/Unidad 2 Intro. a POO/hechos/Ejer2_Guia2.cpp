#include <iostream>
#include <cmath>
using namespace std;

class ecuacion{
	float m_a, m_b, m_c;
	float m_r1, m_r2;
	bool  son_reales;
	
	
public:
	void CargarCoef(float a ,float b,float c);
	void Calcular();
	bool TieneRaicesReales(){return son_reales;};
	float VerRaiz1(){return m_r1;};
	float VerRaiz2(){return m_r2;};
	float VerParteReal(){return m_r1;};
	float VerParteImag(){return m_r2;};
};

	
void ecuacion::Calcular(){
	float d = m_b * m_b - 4 * m_a * m_c;
	if(d>0){
		son_reales = true;
		m_r1=(-m_b + sqrt(d)) / (2 * m_a);
		m_r2=(-m_b - sqrt(d)) / (2 * m_a);}
	else{
		son_reales = false;
		m_r1 = -m_b/(2*m_a);
		m_r2 = sqrt(-d)/ (2 * m_a);
	}
	
}
void ecuacion::CargarCoef(float a ,float b,float c){
	m_a=a;m_b=b;m_c=c;
	Calcular();
}
int main() {
	ecuacion eq;
	eq.CargarCoef(7,29,18);
	if(eq.TieneRaicesReales()){
		cout<<"r1 = "<<eq.VerRaiz1()<<endl;
		cout<<"r2 = "<<eq.VerRaiz2()<<endl;}
	else{
		cout<<"r1 = "<<eq.VerParteReal()<<" + "<<eq.VerParteImag()<<"i"<<endl;
		cout<<"r2 = "<<eq.VerParteReal()<<" - "<<eq.VerParteImag()<<"i"<<endl;
	}
	return 0;
}

