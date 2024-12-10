#include <iostream>
using namespace std;

template<typename T>
T mediana3(T v1, T v2, T v3){
	T aux;
	if(v1<v2 and v1>v3){
		aux = v1;
	} else if(v2<v1 and v2>v3){
		aux = v2;
	}else {
		aux = v3;
	}
	return aux;
}

struct fraccion{ int num,den;};

bool operator<(const fraccion &a, const fraccion &b){ 
	return (a<b);
}
bool operator>(const fraccion &a, const fraccion &b){ 
	return (a>b);
}

int main() {
	
	cout<<"Valor 1: ";float v1;cin>>v1;
	cout<<"Valor 2: ";float v2;cin>>v2;
	cout<<"Valor 3: ";float v3;cin>>v3;
	cout<<endl;
	
	cout<<"Mediana: "<<mediana3(v1,v2,v3);
	cout<<endl;
	
	fraccion nm1;
	cout<<"Num 1: ";cin>>nm1.num;
	cout<<"Den 1: ";cin>>nm1.den;
	cout<<endl;
	
	fraccion nm2;
	cout<<"Num 2: ";cin>>nm2.num;
	cout<<"Den 2: ";cin>>nm2.den;
	cout<<endl;
	
	fraccion nm3;
	cout<<"Num 3: ";cin>>nm3.num;
	cout<<"Den 3: ";cin>>nm3.den;
	cout<<endl;
	
	fraccion aux;
	aux= mediana3(nm1,nm2,nm3);
	cout<<"Num: "<<aux.num<<"Den: "<<aux.den<<endl;
	
	return 0;
}

