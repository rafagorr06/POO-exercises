#include <iostream>
#include <vector>
using namespace std;

class Alumno{
private:
	string m_nombre, m_condicion; 
	int m_DNI, m_notafinal;
public:
	Alumno(string nombre, int dni, int notafinal){
		m_nombre = nombre;
		m_DNI = dni;
		m_notafinal = notafinal;
	}
	string VerNombre(){ return m_nombre;}
	int VerDNI(){ return m_DNI;}
	int VerNotaF(){ return m_notafinal;}
	void Condicion(){
		if (m_notafinal >= 4){
			m_condicion = "R";
		}else{
			m_condicion = "L";
		}
	}
	string VerCondicion(){ return m_condicion;}
};

class Materia{
private:
	string m_nombreM, m_nombreProf;
	vector<Alumno>a;
public:
	Materia(string nombreM, string profe){
		m_nombreM = nombreM;
		m_nombreProf = profe;
	}
	string VerMateria(){ return m_nombreM;}
	string VerProfe(){ return m_nombreProf;}
	void AgregarAlumno(string _nombre, int _dni, int _notafinal){
		Alumno aux(_nombre,_dni,_notafinal);
		a.push_back(aux);
	}
	int CantidadR(){
		int contarR = 0;
		for(int i=0;i<a.size();i++){
			if(a[i].VerCondicion() == "R"){
				++contarR;
			}
		}
		return contarR;
	}
	int CantidadL(){
		int contarL = 0;
		for(int i=0;i<a.size();i++){
			if(a[i].VerCondicion() == "L"){
				++contarL;
			}
		}
		return contarL;
	}
};

int main() {
	
	return 0;
}

