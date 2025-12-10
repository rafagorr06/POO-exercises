#include <iostream>
#include <vector>
using namespace std;

class Ejercicio{
private:
	int m_puntaje; string m_enunciado; bool m_sololibres;
public:
	Ejercicio(int puntaje, string enunciado, bool sololibres){ 
		m_puntaje = puntaje;
		m_enunciado = enunciado;
		m_sololibres = sololibres;
	};
	string VerEnunciado(){ return m_enunciado; }
	int VerPuntajeMaximo(){ return m_puntaje; }
	bool VerSoloLibres(){ return m_sololibres; }
};

class Examen{
private:
	string m_materia;int m_fecha;
	vector<Ejercicio>e;
public:
	Examen(string materia, int fecha){	///a
		m_materia = materia;
		m_fecha = fecha;
	}
	string VerMateria(){ return m_materia; }	///a
	float VerFecha(){ return m_fecha; }	///a
	void AgregarEjercicio(int _puntaje, string _enunciado, bool _sololibres){	///b
		Ejercicio aux(_puntaje,_enunciado,_sololibres);
		e.push_back(aux);
	}
	int VerPuntajeEjercicio(int i){	///c
		return e[i].VerPuntajeMaximo();
	}
	string VerEnunciadoEjercicio(int i){	///c
		return e[i].VerEnunciado();
	}
	bool VerSoloLibresEjercicio(int i){	///c
		return e[i].VerSoloLibres();
	}
	float CalcularCalificacion(vector<int>ejers){
		float suman = 0;
		int cant= e.size();
		for(int i=0;i<cant;i++){
			suman += ejers[i];
		}
		float sumaE = 0;
		for(int i=0;i<cant;i++){
			sumaE += e[i].VerPuntajeMaximo();
		}
		return ((suman*100)/sumaE);
	}
};

int main() {
	
	cout<<"Materia del Examen: ";string materia;cin>>materia;
	cout<<"Fecha del Examen(aaaammdd): ";float fecha;cin>>fecha;
	Examen E1(materia,fecha);
	cout<<endl;
	
	cout<<"Cantidad de ejercicios: ";int cant;cin>>cant;
	
	int puntaje; string enunciado; bool sololibres;
	for(int i=0;i<cant;i++){
		cout<<"Puntaje: ";cin>>puntaje;
		cout<<"Enunciado: ";cin>>enunciado;
		cout<<"¿Solo libres?(1 si, 0 no): ";cin>>sololibres;
		E1.AgregarEjercicio(puntaje,enunciado,sololibres);
	}
	cout<<endl;
	
	vector<int>notaejers(cant);
	for(int i=0;i<cant;i++){
		int nota = 0;
		cout<<"Nota del Ejercicio nro "<<notaejers[i]<<": ";cin>>nota;
		notaejers[i] = nota;
	}

	cout<<endl;
	
	cout<<"La calificacion es de: "<<E1.CalcularCalificacion(notaejers);
	
	
	return 0;
}

