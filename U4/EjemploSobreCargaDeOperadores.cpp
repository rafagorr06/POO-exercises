#include <iostream>
using namespace std;

class Complejo {	float preal,pimag;	public:	Complejo(float a=0, float b=0) {preal=a;pimag=b;};	float ver_preal() {return preal;};	float ver_pimag() {return pimag;};};Complejo operator+(Complejo a, Complejo b){   Complejo x(a.ver_preal()+b.ver_preal(),a.ver_pimag()+b.ver_pimag());return x;}ostream &operator<<(ostream &w, Complejo &c){	if (c.ver_pimag()<0)		w<<c.ver_preal()<<c.ver_pimag()<<"i"<<endl;	else		w<<c.ver_preal()<<"+"<<c.ver_pimag()<<"i"<<endl;	return w;}int main(int argc, char *argv[]) {	Complejo c1(2,-5), c2(9,-2),c3;	c3=c1+c2;	cout<<c3<<endl;	return 0;}


