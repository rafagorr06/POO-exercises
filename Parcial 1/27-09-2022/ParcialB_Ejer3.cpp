#include <iostream>
#include <vector>
using namespace std;

class Bien{
private:
	float m_valor;
public:
	Bien(float valor){ m_valor= valor;}
	float VerValor(){ return m_valor;}
	virtual float Amortizar()=0;
};

class Mueble : public Bien{
private:
	int m_anio;
public:
	Mueble(int anio, float valorM): Bien(valorM){ m_anio= anio;}
	int VerAnio(){ return m_anio;}
	float Amortizar() override{ return (this->VerValor()*(2022-m_anio)*0.05);}
};

class Inmueble : public Bien{
public:
	Inmueble(float valorI): Bien(valorI){}
	float Amortizar() override{ return 0.0;}
};

class Rodado : public Bien{
private:
	float m_km;
public:
	Rodado(float km, float valorR): Bien(valorR){ m_km= km;}
	float Amortizar() override{ return ((this->VerValor()*m_km)/10000);}
};
int main() {
	vector<Bien*>bienes(3);
	for(int i=0;i<bienes.size();i++){
		if(i == 0){
			cout<<"Valor del mueble: ";float vM;cin>>vM;
			cout<<"Año de creación: ";int aM;cin>>aM;
			bienes[i]= new Mueble(aM,vM);
		}
		if(i == 1){
			cout<<"Valor del inmueble: ";float vI;cin>>vI;
			bienes[i]= new Inmueble(vI);
		}
		if(i == 2){
			cout<<"Valor del rodado: ";float vR;cin>>vR;
			cout<<"Km: ";float kmR;cin>>kmR;
			bienes[i]= new Rodado(kmR,vR);
		}
	}
	for(Bien *p : bienes){
		cout<<p->Amortizar()<<endl;
	}
	for(Bien *p : bienes){
		delete p;
	}
	return 0;
}

