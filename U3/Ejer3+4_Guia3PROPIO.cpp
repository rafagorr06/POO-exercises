#include <iostream>
#include <cmath>
using namespace std;
	
	struct Punto{
		float x,y;
	};

	bool son_muy_parecidos(float x, float y){
		return fabs(x-y)<1e-5;
	}

	class Recta{
	public:
		virtual string ObtenerEcuacion() = 0;
		virtual bool Pertenece(Punto p) = 0;
		virtual ~Recta(){};
	};
	
	class RectaExplicita : public Recta{
	private:
		float m,b;
	public:
		RectaExplicita(Punto p, Punto q){
			m = ((q.y-p.y)/(q.x-q.y));
			b= (p.y - m*p.x);
		}
		string ObtenerEcuacion()override{
			return "y = " + to_string(m) + "*x + " + to_string(b);
		}
		float verM(){
			return m;
		}
		float verB(){
			return b;
		};
		bool Pertenece(Punto p)override{
			return son_muy_parecidos(p.y,m*p.x+b);
		}
	};

	class RectaGeneral : public Recta{
	private:
		float a,b,c;
	public:
		RectaGeneral(Punto p, Punto q){
			a= (q.x - p.x);
			b= (p.y - q.y);
			c= (-a*p.x - b*p.y);
		};
		string ObtenerEcuacion()override{
			return to_string(a) + "*x + " + to_string(b) + "*y + " + to_string(c) + " = 0";
		}
		float verA(){
			return a;
		}
		float verB(){
			return b;
		};
		float verC(){
			return c;
		};
		bool Pertenece(Punto p)override{
			return son_muy_parecidos(a*p.x+b*p.y+c,0);
		}
	};
	
int main() {
	Punto p = {1,2}, q = {2,1};
	int cual;
	cin>>cual;
	Recta *re;
	if(cual == 1){
		re = new RectaExplicita(p,q);
	}
	else{
		re = new RectaGeneral(p,q);
	}
	cout<<re->ObtenerEcuacion()<<endl;
	cout<<re->Pertenece({0,3})<<endl;
	cout<<re->Pertenece({0,3.1})<<endl;
	
	delete re;
	return 0;
}

