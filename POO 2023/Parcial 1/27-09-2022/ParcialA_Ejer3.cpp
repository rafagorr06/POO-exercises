#include <iostream>
#include <vector>
using namespace std;

class Empleado{
private:
	int m_dni; string m_n, m_a; float m_sb;
public:
	Empleado(int dni, string n, string a, float sb){
		m_dni= dni; m_n= n; m_a= a; m_sb= sb;
	}
	int VerDNI(){ return m_dni;}
	string VerNombre(){ return m_n;}
	string VerApellido(){ return m_a;}
	float VerSueldoBasico(){ return m_sb;}
	virtual float MontoACobrar()= 0; ///Metodo virtual puro, el cual hace a la clase abstracta, y con el que las hijas pueden trabajar de forma individual
};

class Constructor : public Empleado{
private:
	int m_hextras, m_mtscub;
public:
	Constructor(int hextras, int mtscub, int dni, string n, string a, float sb) : Empleado(dni, n, a,sb){ ///Cuando debemos pasarle datos a la clase base, o madre, se hace de esta forma
		m_hextras= hextras; m_mtscub= mtscub;
	}
	float MontoACobrar()override{
		float x= (this->VerSueldoBasico()+300*m_hextras+100*m_mtscub); ///Usamos el this para poder acceder a los atributos cargados en la clase madre a traves de los metodos establecidos
		return x;
	}
};

class Instalador : public Empleado{
private:
	int m_diasT;
public:
	Instalador(int diasT, int dni, string n, string a, float sb) : Empleado(dni, n, a,sb){
		m_diasT= diasT;
	}
	float MontoACobrar()override{
		float x= (this->VerSueldoBasico()+m_diasT*3000);
		return x;
	}
};

class Yesero : public Empleado{
private:
	int m_mtscua;
public:
	Yesero(int mtscua, int dni, string n, string a, float sb) : Empleado(dni, n, a,sb){
		m_mtscua= mtscua;
	}
	float MontoACobrar()override{
		float x= (this->VerSueldoBasico()+200*m_mtscua);
		return x;
	}
};

float TotalPagar(vector<Empleado*>empleados){ ///Al pedirnos un vector de tipo Empleado que a su vez, tiene clases hijas, el empleado se transforma a un puntero
	float suma= 0;
	for(int i=0;i<empleados.size();i++){
		suma+= empleados[i]->MontoACobrar(); ///Al ser un metodo virtual con el que interactuamos, y ademas de trabajar con un vector puntero, se usa la -> para acceder a los metodos correspondientes
	}
	return suma;
}
int main() {
	vector<Empleado*>EmpleadosA(3);

	for(int i=0;i<EmpleadosA.size();i++){
		cout<<"Eliga tipo de empleado: Constructor(1), Instalador(2), Yesero(3): ";int tipo;cin>>tipo;
		cout<<endl;
		if(tipo == 1){
			cout<<"Horas extras: ";int hextrasC;cin>>hextrasC;
			cout<<"Metros cubiertos: ";int mtscubC;cin>>mtscubC;
			cout<<"DNI: ";int DNIC;cin>>DNIC;
			cout<<"Nombre: ";string nC;cin>>nC;
			cout<<"Apellido: ";string aC;cin>>aC;
			cout<<"Sueldo Basico: ";float sbC;cin>>sbC;
			EmpleadosA[i]= new Constructor(hextrasC,mtscubC,DNIC,nC,aC,sbC); ///Como trabajamos con punteros, la asignacion se hace implementando un New, y el tipo de empleado en este caso especifico
		}else if(tipo == 2){
			cout<<"Dias trabajados: ";int diasTI;cin>>diasTI;
			cout<<"DNI: ";int DNII;cin>>DNII;
			cout<<"Nombre: ";string nI;cin>>nI;
			cout<<"Apellido: ";string aI;cin>>aI;
			cout<<"Sueldo Basico: ";float sbI;cin>>sbI;
			EmpleadosA[i]= new Instalador(diasTI,DNII,nI,aI,sbI);;
		}else{
			cout<<"Metros cuadrados: ";int mtscuaY;cin>>mtscuaY;
			cout<<"DNI: ";int DNIY;cin>>DNIY;
			cout<<"Nombre: ";string nY;cin>>nY;
			cout<<"Apellido: ";string aY;cin>>aY;
			cout<<"Sueldo Basico: ";float sbY;cin>>sbY;
			EmpleadosA[i]= new Yesero(mtscuaY,DNIY,nY,aY,sbY);
		}
	}
	float calculo = TotalPagar(EmpleadosA);
	cout<<"Total a pagar por la empresa: "<<calculo<<endl;
	return 0;
}

