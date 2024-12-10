#include <iostream>
using namespace std;

class Fecha{
private:
	int m_dia; int m_mes; int m_anio;
public:
	Fecha(int dia, int mes, int anio){
		m_dia = dia;
		m_mes = mes;
		m_anio = anio;
	};
	int VerAnio(){
		return m_anio;
	}
	int VerMes(){
		return m_mes;
	}
	int VerDia(){
		return m_dia;
	}
	int DiferenciaAnios(Fecha x){
		int diferencia = m_anio - x.m_anio;
		return diferencia;
	}
	string SignoZ(int x){
		switch(x){
		case 1: return "Acuario";
		case 2: return "cancer";
		}
	};
};

int main() {
	
	cout<<"Año: ";int anio;cin>>anio;
	cout<<"Mes: ";int mes;cin>>mes;
	cout<<"Dia: ";int dia;cin>>dia;
	Fecha f1(dia,mes,anio);
	
	cout<<endl;
	
	cout<<"Su año es: "<<f1.VerAnio()<<endl;
	cout<<"Su mes es: "<<f1.VerMes()<<endl;
	cout<<"Su dia es: "<<f1.VerDia()<<endl;
	
	cout<<endl;
	
	cout<<"Año para calcular diferencia: ";int anio2;cin>>anio2;
	Fecha f2(0,0,anio2);
	cout<<"La diferencia de años es: "<<f1.DiferenciaAnios(f2)<<endl;
	
	cout<<"Su signo zodiacal es: "<<f1.SignoZ(mes);
	return 0;
}

