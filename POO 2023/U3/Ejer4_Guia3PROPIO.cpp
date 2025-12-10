#include <iostream>
#include <cmath>
using namespace std;
	
	struct Punto{
		float x,y;
	};

	bool son_muy_parecidos(float x, float y){
		return fabs(x-y)<1e-5;
	}
		
	class RectaGeneral{
	private:
		float a,b,c;
	public:
		RectaGeneral(Punto p, Punto q){
			a= (q.x - p.x);
			b= (p.y - q.y);
			c= (-a*p.x - b*p.y);
		};
		string ObtenerEcuacion(){
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
		bool Pertenece(Punto p){
			return son_muy_parecidos(a*p.x+b*p.y+c,0);
		}
	};

int main() {
	Punto p = {1,2}, q = {2,1};
	RectaGeneral re(p,q);
	cout<<re.ObtenerEcuacion()<<endl;
	cout<<re.Pertenece({0,3})<<endl;
	cout<<re.Pertenece({0,3.1})<<endl;
	return 0;
}

