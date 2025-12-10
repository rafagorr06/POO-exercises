#include <iostream>#include <cmath>using namespace std;class  lata_g{private:	float radio,altura,vol; public:	 	lata_g(float pr, float pa);	void calcular_vol();	float ver_vol() { return vol;};};lata_g::lata_g(float pr, float pa){	radio=pr; altura=pa; }void lata_g::calcular_vol(){	vol= 3.14*radio*radio*altura;}int main(int argc, char *argv[]) {	float r,a;	cout<<"Radio de la lata:";cin>>r;	cout<<"Altura de la la lata:"; cin>>a; 	lata_g x(r,a);   //x es instancia de la clase lata_g		x.calcular_vol();	cout<<"El volumen de la lata es:"<<x.ver_vol()<<endl;	return 0;}


