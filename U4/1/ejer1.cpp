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
		Racional x1((m_num*r2.VerDen())+(r2.VerNum()*m_den),(m_den*r2.VerDen()));
		return x1;
	}
	Racional operator*(Racional r5){
		Racional x(((m_num)*r5.VerNum()),(m_den*r5.VerDen()));
		return x;
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
	Racional operator>(Racional r3){
		if(m_num/m_den > (r3.VerNum()/r3.VerDen())){
			return *this;
		}else{
			return r3;
		}
	}
	Racional operator<(Racional r3){
		if(m_num/m_den < (r3.VerNum()/r3.VerDen())){
			return r3;
		}else{
			return *this;
		}
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
	
	Racional d(10,5), e(20,20), x(0,0);
	
	x = d>e;
	cout<<"d>e"<<endl;
	cout<<x.VerNum()<<" "<<x.VerDen()<<endl;
	
	Racional f(300,30), g(10,10);
	x = f<g;
	cout<<"f<g"<<endl;
	cout<<x.VerNum()<<" "<<x.VerDen()<<endl;
	
	return 0;
}
