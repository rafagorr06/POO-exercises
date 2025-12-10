#include <iostream>
using namespace std;

class Racional {
public:
	Racional(int num, int den) : m_num(num), m_den(den) { }
	
	int VerNum() const { return m_num; }
	int VerDen() const { return m_den; }
	
	Racional operator* (const Racional &x) {
		return Racional (m_num*x.VerNum(),m_den*VerDen());
	}
	
	Racional operator+ (const Racional &x) {
		return Racional (m_num*x.VerDen()+VerNum()*m_den,m_den*VerDen());
	}
	
private:
		int m_num, m_den;
};


bool operator< (const Racional& r1, const Racional& r2) {
	return (r1.VerNum() * r2.VerDen()) < (r2.VerNum() * r1.VerDen());
}

bool operator<= (const Racional& r1, const Racional& r2) {
	return (r1.VerNum() * r2.VerDen()) <= (r2.VerNum() * r1.VerDen());
}

bool operator> (const Racional& r1, const Racional& r2) {
	return r2 < r1;
}

bool operator>= (const Racional& r1, const Racional& r2) {
	return r2 <= r1;
}

bool operator== (const Racional& r1, const Racional& r2) {
	return (r1.VerNum() * r2.VerDen()) == (r2.VerNum() * r1.VerDen());
}

bool operator!= (const Racional& r1, const Racional& r2) {
	return !(r1 == r2);
}


int main() {
	Racional a(3, 5), b(2, 3), c(6, 10);;
	Racional aux = a + b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	aux = a * b;
	cout << aux.VerNum() << '/' << aux.VerDen() << endl;
	
	return 0;

}
