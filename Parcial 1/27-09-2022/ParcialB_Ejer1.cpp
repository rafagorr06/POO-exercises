#include <iostream>
#include <cmath>
using namespace std;

class Vec2{ ///Vector de posiciones, x e y
private:
	float m_x, m_y;
public:
	Vec2(float x, float y){ m_x= x; m_y=y;}
	float VerX(){ return m_x;}
	float VerY(){ return m_y;}
	float Modulo(){ return sqrt(m_x*m_x+m_y*m_y);}
	Vec2 operator+(Vec2 v2){ return Vec2(this->m_x+v2.VerX(),this->m_y+v2.VerY());}
	Vec2 operator-(Vec2 v2){ return Vec2(this->m_x-v2.VerX(),this->m_y-v2.VerY());}
};

class Proyectil{
private:
	Vec2 m_pos, m_vel; ///Posicion tiene 2 dimensiones, x e y, al igual que la velocidad
public:
	Proyectil(Vec2 pos, Vec2 vel): m_pos(pos), m_vel(vel){}
	void Mover(){ m_pos= m_pos+ m_vel;}
	bool Colisiona(Vec2 pos2, float radio){
		Vec2 aux= pos2-m_pos;
		if(aux.Modulo() < radio){
			return true;
		}else{ return false;}
	}
};

int main() {
	
	return 0;
}

