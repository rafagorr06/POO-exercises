#include <iostream>
#include <vector>
using namespace std;

struct Alumno{
	string nombre;
	float nota;
};

class Curso{
private:
	string m_materia;
	vector<Alumno>v;
public:
	Curso(string materia){
		m_materia = materia;
	}
	void AgregarAlumno(Alumno &x){
		v.push_back(x);
	}
	float PromedioCurso(){
		float suma=0;
		for(int i=0;i<v.size();i++){
			suma+=v[i].nota;
		}
		return suma/v.size();
	}
	Alumno MejorAlumno(){
		Alumno mejor;
		mejor.nota=0;
		for(int i=0;i<v.size();i++){
			if(v[i].nota > mejor.nota){
				mejor = v[i];
			}
		}
		return mejor;
	}
	string NombreCurso(){
		return m_materia;
	}
	string VerNombreA(int x){
		return v[x].nombre;
	}
	float VerNotaA(int x){
		return v[x].nota;
	}
	int CantCurso(){
		return v.size();
	}
};
int main() {
	
	cout<<"Nombre de la materia: ";string materia;cin>>materia;
	Curso c(materia);
	
	Alumno x;
	cout<<"Cantidad de alumnos: ";int cant;cin>>cant;
	for(int i=0; i<cant; i++){
		cout<<"Nombre: ";cin>>x.nombre;
		cout<<"Nota: ";cin>>x.nota;
		c.AgregarAlumno(x);
	}
	
	cout<<endl;
	
	cout<<"Lista de "<<c.NombreCurso();
	cout<<endl;
	
	cout<<"Cantidad de alumnos: "<<c.CantCurso()<<endl;
	for(int i=0; i<c.CantCurso();i++){
		cout<<"Nombre del alumno: "<<c.VerNombreA(i)<<" con nota: "<<c.VerNotaA(i)<<endl;
	}
	
	cout<<endl;
	
	cout<<"El promedio del curso es de: "<<c.PromedioCurso()<<endl;
	
	cout<<endl;
	
	x = c.MejorAlumno();
	
	cout<<"Nombre del mejor alumno: "<<x.nombre<<" con nota "<<x.nota<<endl;
	return 0;
}

