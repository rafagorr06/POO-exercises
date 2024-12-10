#include <iostream>
using namespace std;

class Hora{
private:
	int m_hor; int m_min; int m_seg;
public:
	Hora(int hora, int min, int seg){
		m_hor = hora;
		m_min = min;
		m_seg = seg;
	}
	int VerHora(){
		return m_hor;
	}
	int VerMin(){
		return m_min;
	}
	int VerSeg(){
		return m_seg;
	}
	bool operator<=(Hora r2){
		float h1= m_hor + m_min + m_seg;
		float h2= r2.VerHora() + r2.VerMin() + r2.VerSeg();
		return h1<=h2;
	}
};

int main() {
	
	cout<<"Primera hora"<<endl;
	cout<<"Hora: ";int hor1;cin>>hor1;
	cout<<"Min: ";int min1;cin>>min1;
	cout<<"Seg: ";int seg1;cin>>seg1;
	Hora h1(hor1,min1,seg1);
	cout<<endl;
	
	cout<<"Segunda hora"<<endl;
	cout<<"Hora: ";int hor2;cin>>hor2;
	cout<<"Min: ";int min2;cin>>min2;
	cout<<"Seg: ";int seg2;cin>>seg2;
	Hora h2(hor2,min2,seg2);
	cout<<endl;
	
	if(h1.operator<=(h2) == 0){
		cout<<"La hora mayor es"<<endl;
		cout<<h1.VerHora()<<":"<<h1.VerMin()<<":"<<h1.VerSeg()<<endl;
		cout<<"La hora menor es"<<endl;
		cout<<h2.VerHora()<<":"<<h2.VerMin()<<":"<<h2.VerSeg()<<endl;
	}else{
		cout<<"La hora mayor es"<<endl;
		cout<<h2.VerHora()<<":"<<h2.VerMin()<<":"<<h2.VerSeg()<<endl;
		cout<<"La hora menor es"<<endl;
		cout<<h1.VerHora()<<":"<<h1.VerMin()<<":"<<h1.VerSeg()<<endl;
	}
	
	
	
	return 0;
}

