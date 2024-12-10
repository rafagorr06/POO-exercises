#include <iostream>
using namespace std;

class Persona{
	private:
		string m_apellido, m_nombre, m_estcivil;
		int m_dni, m_fechan;
	public:
		Persona(string apellido, string nombre, string estcivil, int dni, int fechan){
			m_apellido = apellido;
			m_nombre = nombre;
			m_estcivil = estcivil;
			m_dni = dni;
			m_fechan = fechan;
		}
		int Edad(int fechahoy){
			int anio = (fechahoy/10000-m_fechan/10000);
			return anio;
		}
		string VerNombre(){
			return m_nombre;
		}
		string VerApellido(){
			return m_apellido;
		}
		string VerEstadoCivil(){
			return m_estcivil;
		}
		int VerDNI(){
			return m_dni;
		}
};
class Alumno : public Persona{
	private:
		float m_promedio; int m_materiasapr;
	public:
		Alumno(float promedio, int materias, string apellido, string nombre, string estcivil, int dni, int fechan){
			Persona(apellido,nombre,estcivil,dni,fechan);
			m_promedio = promedio;
			m_materiasapr = materias;
		}
		float MeritoAcademico(){
			return m_promedio*m_materiasapr;
		};

};
class Docente : public Persona{
	private:
		int m_fechaing;
	public:
		Docente(int ingreso, string apellido, string nombre, string estcivil, int dni, int fechan): Persona(apellido, nombre, estcivil, dni, fechan){
			m_fechaing = ingreso;
		}
		int Antiguedad(int fechahoy){
			int ant = (fechahoy/10000-m_fechaing/10000);
			return ant;
		}
};

int main() {
	
	int hoy;
	cout<<"Buenos dias, ingrese la fecha del dia de hoy(añomesdia): ";cin>>hoy;
	
	string apellido, nombre, estadocivil;
	int DNI, fechanac, matapr,fechadeingreso;
	float prom;
	cout<<"Ingrese los datos del alumno correspondiente"<<endl;
	cout<<"Por favor, ingrese la informacion en el siguiente modo"<<endl;
	cout<<endl;
	cout<<"Apellido: ";cin>>apellido;
	cout<<"Nombre: ";cin>>nombre;
	cout<<"Estado Civil: ";cin>>estadocivil;
	cout<<"DNI: ";cin>>DNI;
	cout<<"Fecha de nacimiento: ";cin>>fechanac;
	cout<<"Promedio: ";cin>>prom;
	cout<<"Materias aprobadas: ";cin>>matapr;
	
	Alumno A1(prom,matapr,apellido,nombre,estadocivil,DNI,fechanac);
	
	cout<<"El alumno: "<<A1.VerApellido()<<", "<<A1.VerNombre()<<" de edad "<<A1.Edad(hoy)<<" años, cuenta con merito academico de: "<<A1.MeritoAcademico()<<"%";
	
	cout<<endl;
	cout<<endl;
	
	cout<<"Ingrese los datos del docente correspondiente"<<endl;
	cout<<"Por favor, ingrese la informacion en el siguiente modo"<<endl;
	cout<<endl;
	cout<<"Apellido: ";cin>>apellido;
	cout<<"Nombre: ";cin>>nombre;
	cout<<"Estado Civil: ";cin>>estadocivil;
	cout<<"DNI: ";cin>>DNI;
	cout<<"Fecha de nacimiento: ";cin>>fechanac;
	cout<<"Fecha de ingreso a la institucion: ";cin>>fechadeingreso;
	
	Docente D1(fechadeingreso,apellido,nombre,estadocivil,DNI,fechanac);
	
	cout<<"El docente: "<<D1.VerApellido()<<", "<<D1.VerNombre()<<" de edad "<<D1.Edad(hoy)<<" años, cuenta con una antiguedad de: "<<D1.Antiguedad(hoy)<<" años";
	return 0;
}

