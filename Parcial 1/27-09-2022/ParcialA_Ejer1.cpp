#include <iostream>
using namespace std;

class Estado{
private:
	int m_nivel=1; int m_vida; int m_pts=0;
public:
	Estado(int vida){ m_vida= vida;} ///Leo solo la vida por Constructor, por solicitud de enunciado
	int VerNivel(){ return m_nivel;} ///Establezco metodos para ver sus atributos
	int VerVIda(){ return m_vida;}
	int VerPts(){ return m_pts;}
	bool Estavivo(){ return m_vida>0;}	///Un metodo bool para saber si el Personaje esta vivo
	void IncrementarNivel(){ m_nivel+= 1;}
	void IncrementarPts(int puntaje){ m_pts+= puntaje;}
};

Estado operator>(Estado n1,Estado n2){
	if(n1.VerNivel() > n2.VerNivel()){
		return n1;
	}else if(n2.VerNivel() > n1.VerNivel()){
		return n2;
	}else if(n1.VerPts() > n2.VerPts()){
		return n1;
	}else{
		return n2;
	}
}

class Personaje{
private:
	string m_nombre; int m_x, m_y; Estado P;
public:
	Personaje(string nombre, int x, int y, int vidas) : P(vidas){
		m_nombre= nombre; m_x= x; m_y= y;
	}
	string VerNombre(){ return m_nombre;}
	int VerX(){ return m_x;}
	int VerY(){ return m_y;}

	void VariarPos(int vx, int vy){
		m_x= vx; m_y= vy;
	}
	void VariarEstado(int pt){
		P.IncrementarNivel();
		P.IncrementarPts(pt);
	}
	int VerEn(){ return P.VerNivel();}
	int VerEv(){ return P.VerVIda();}
	int VerEp(){ return P.VerPts();}
};



int main() {
	cout<<"Vidas del primer jugador: ";int vidaA;cin>>vidaA;
	Estado eA(vidaA);
	cout<<endl;
	cout<<"Nombre: ";string nombreA;cin>>nombreA;
	cout<<"Pos X: ";int xA;cin>>xA;
	cout<<"Pos Y: ";int yA;cin>>yA;
	int ptsA = (100+rand()%150);
	cout<<"Puntaje de "<<nombreA<<": "<<ptsA<<endl;
	Personaje A(nombreA,xA,yA,vidaA);
	if(eA.Estavivo() == 0){
		cout<<A.VerNombre()<<" murio"<<endl;
	}else{ cout<<A.VerNombre()<<" esta vivo"<<endl;}
	
	cout<<endl;
	
	cout<<"Vidas del segundo jugador: ";int vidaB;cin>>vidaB;
	Estado eB(vidaB);
	cout<<endl;
	cout<<"Nombre: ";string nombreB;cin>>nombreB;
	cout<<"Pos X: ";int xB;cin>>xB;
	cout<<"Pos Y: ";int yB;cin>>yB;
	int ptsB = (100+rand()%150);
	cout<<"Puntaje de "<<nombreB<<": "<<ptsB<<endl;
	Personaje B(nombreB,xB,yB,vidaB);
	if(eB.Estavivo() == 0){
		cout<<B.VerNombre()<<" murio"<<endl;
	}else{ cout<<B.VerNombre()<<" esta vivo"<<endl;}
	
	cout<<endl;
	
	eA.IncrementarPts(ptsA);
	eB.IncrementarPts(ptsB);
	
	Estado OO(0);
	OO=eA>eB;
	cout<<"El mayor es"<<endl;
	cout<<"Nivel: "<<OO.VerNivel()<<endl;
	cout<<"Vida: "<<OO.VerVIda()<<endl;
	cout<<"Pts: "<<OO.VerPts()<<endl;
	return 0;
}

