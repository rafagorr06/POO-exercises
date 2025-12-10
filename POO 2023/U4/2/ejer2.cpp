#include <iostream>
using namespace std;

class Racional{
private:
	int m_num, m_den;
public:
	Racional(int num, int den){
		m_num = num;
		m_den = den;
	}
	int VerNum(){
		return m_num;
	}
	int VerDen(){
		return m_den;
	}
	Racional operator+(Racional r2){
		Racional x1((this->m_num*r2.VerDen())+(r2.VerNum()*this->m_den), (this->m_den*r2.VerDen()));
		return x1;
	}
	Racional operator*(Racional r5){
		Racional x2(((m_num)*r5.VerNum()),(m_den*r5.VerDen()));
		return x2;
	}
	Racional &operator++(){
		m_num+=m_den;
		return *this;
	}
	Racional operator++(int){
		Racional aux = *this;
		m_num+=m_den;
		return aux;
	}
	bool operator>(Racional r2){
		int x = (this->m_num*r2.VerDen()), x2 =(r2.VerNum()*this->m_den);
		return (x > x2);
	}
};

int main() {
	Racional a(3,5), b(2,3), c(0,0);
	
	c=a+b;
	cout<<"c=a+b"<<endl;
	cout<<c.VerNum()<<" "<<c.VerDen()<<endl;
	
	cout<<endl;
	
	c=a*b;
	cout<<"c=a*b"<<endl;
	cout<<c.VerNum()<<" "<<c.VerDen()<<endl;
	
	cout<<endl;
	
	c=a+b+c;
	cout<<"c=a+b+c"<<endl;
	cout<<c.VerNum()<<" "<<c.VerDen()<<endl;
	
	cout<<endl;
	
	c=a*b*c;
	cout<<"c=a*b*c"<<endl;
	cout<<c.VerNum()<<" "<<c.VerDen()<<endl;
	
	cout<<endl;
	
	b=c++;
	cout<<"b=c++"<<endl;
	cout<<b.VerNum()<<" "<<b.VerDen()<<endl;
	
	cout<<endl;
	
	a=++c;
	cout<<"a=++c"<<endl;
	cout<<a.VerNum()<<" "<<a.VerDen()<<endl;
	
	cout<<endl;
	
	////////////////////////////////////////////////////////////////////////
	return 0;
}
