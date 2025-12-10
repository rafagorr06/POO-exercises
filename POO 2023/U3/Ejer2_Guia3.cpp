#include <iostream>
#include <vector>
using namespace std;

struct Fecha { int d,m,a; };

int dif_anios(Fecha f1, Fecha f2) {
	int x1 = f1.a*10000+f1.m*100+f1.d;
	int x2 = f2.a*10000+f2.m*100+f2.d;
	return (x2-x1)/10000;
}

class Persona {
public:
	Persona(string n, string a, string ec, int d, Fecha f) 
		: nom(n), ape(a), estado(ec), dni(d), fnac(f) 
	{
		
	}
	string VerNombre() { return nom; }
	string VerApellido() { return ape; }
	string VerEstadoCivil() { return estado; }
	int VerDNI() { return dni; }
	Fecha VerFechaNacimiento() { return fnac; }
	int CalcularEdad(Fecha fhoy) { return dif_anios(fnac,fhoy); }
private:
	string nom, ape, estado;
	int dni;
	Fecha fnac;
};

class Alumno : public Persona {
public:
	Alumno(string n, string a, string ec, int d, Fecha f, int cm, float p) 
		: Persona(n,a,ec,d,f), cant_mat(cm), prom(p) { }
	int VerCantMaterias() { return cant_mat; }
	float VerPromedio() { return prom; }
	float CalcularMeritoAcademico() { return prom*cant_mat; }
private:
	int cant_mat;
	float prom;
};

class Docente : public Persona {
public:
	Docente(string n, string a, string ec, int d, Fecha f, Fecha i) 
		: Persona(n,a,ec,d,f), fing(i) { }
	Fecha VerFechaIngreso() { return fing; }
	int CalcularAntiguedad(Fecha fhoy) { return dif_anios(fing,fhoy); }
private:
	Fecha fing;
};

class Curso {
public:
	Curso(string m, Docente d) : materia(m), docente(d) { }
	Docente VerDocente() { return docente; }
	int CantAlumnos() { return alumnos.size(); }
	bool AgregarAlumno(Alumno a) {
		if (alumnos.size()==50) return false;
		alumnos.push_back(a);
		return true;
	}
	Alumno VerAlumno(int i) { return alumnos[i]; }
	Alumno MejorPromedio() {
		Alumno mejor = alumnos[0];
		for(Alumno &a : alumnos) 
			if (a.VerPromedio()>mejor.VerPromedio())
				mejor = a;
		return mejor;
	}
private:
	string materia;
	Docente docente;
	vector<Alumno> alumnos;
};

int main() {
	
	Curso poo("POO", Docente("Pablo","Novara",...etc...) );
	
	poo.AgregarAlumno( Alumno("Juan","Perez",...etc...) );
	poo.AgregarAlumno( Alumno("Jose","Rodriguez",...etc...) );
	poo.AgregarAlumno( Alumno("Carlos","Martinez",...etc...) );
	
	...
	
	return 0;
}

