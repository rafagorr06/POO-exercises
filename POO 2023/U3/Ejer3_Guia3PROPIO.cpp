#include <iostream>
#include <cmath>
using namespace std;
	
	struct Punto{
		float x,y;
	};

	bool son_muy_parecidos(float x, float y){
		return fabs(x-y)<1e-5;
	}
		
	class RectaExplicita{
	private:
		float m,b;
	public:
		RectaExplicita(Punto p, Punto q){
			m = ((q.y-p.y)/(q.x-q.y));
			b= (p.y - m*p.x);
		}
		string ObtenerEcuacion(){
			return "y = " + to_string(m) + "*x + " + to_string(b);
		}
		float verM(){
			return m;
		}
		float verB(){
			return b;
		};
		bool Pertenece(Punto p){
			return son_muy_parecidos(p.y,m*p.x+b);
		}
	};

int main() {
	Punto p = {1,2}, q = {2,1};
	RectaExplicita re(p,q);
	cout<<re.ObtenerEcuacion()<<endl;
	cout<<re.Pertenece({0,3})<<endl;
	cout<<re.Pertenece({0,3.1})<<endl;
	return 0;
}

