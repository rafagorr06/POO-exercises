#include <iostream>
using namespace std;

struct Fecha {
	int dia, mes, anio;
};

class Persona {
public:
	Persona (string nombre, string apellido, Fecha fecnac){
		m_nom = nombre;
		m_ape = apellido;
		m_fec_nac = fecnac;
	}
	int CalcularEdad(Fecha fec_hoy){
		return fec_hoy.anio - m_fec_nac.anio;
	}
	
protected:
	string m_ape, m_nom;
	Fecha m_fec_nac;
	
};

class Alumno : public Persona {
public:
	Alumno (string nombre, string apellido, Fecha nacim) : Persona (m_nom, m_ape, m_fec_nac){
		promedio = 0.0;
		cant_aprob = 0;
	}
	
	void AgregarMateria(float nota){
		float sumTotal = (promedio * cant_aprob) + nota;
		cant_aprob++;
		promedio = sumTotal / cant_aprob;
	}
	
	float CalcularMeritoAcademico(){return promedio * cant_aprob;}

private:
	string m_nombrealu, m_apealu;
	Fecha m_fec_nac_alu;
	float promedio;
	int cant_aprob;
};

class Docente : public Persona {
public:
	Docente (string nombre, string apellido, Fecha fec_entra) : Persona (nombre, apellido, fec_entra){
		m_fec_ingr = fec_entra;
	}
	
	int CalcularAntiguedad(Fecha fec_hoy){return fec_hoy.anio - m_fec_ingr.anio;}
	
private:
	string m_nom, m_ape;
	Fecha m_fec_ingr;
};

int main() {
	Fecha fec_hoy {18,12,2025};
	Fecha fec1 {9,12,2005};
	Alumno alu1("Juan","Perez",fec1);
	Fecha fec2 {7,7,1983};
	Docente doc1("Alba","Rogriguez",fec2);
	doc1.CalcularAntiguedad(fec_hoy);
	float nota;
	int N;
	cin >> nota;
	alu1.AgregarMateria(nota);
	alu1.CalcularMeritoAcademico();
	return 0;
}

