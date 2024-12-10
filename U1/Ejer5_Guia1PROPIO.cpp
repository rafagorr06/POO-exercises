#include <iostream>
using namespace std;

int *buscar(int *v, int n){
	int *v1 = new int[n];
	int *may;
	for(int i=0;i<n;++i){
		if(*(v1+i) > 0){
			may = (v1+i); 
		}
	}
	delete v1;
	return may;
}


int main() {
	int N;
	cout<<"Tamaño de lista de nros"<<endl;
	cin>>N;
	int *v = new int[N];
	for(int i=0;i<N;++i){
		*(v+i) = 1000+rand()%1500;
		cout<<*(v+i)<<"  ";
	}
	cout<<endl;
	
	int *b;
	b= buscar(v,N);
	cout<<b<<endl;
	
	delete []v;
	
	return 0;
}

