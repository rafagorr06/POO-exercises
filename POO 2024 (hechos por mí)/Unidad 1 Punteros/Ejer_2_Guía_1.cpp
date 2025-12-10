#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int *p=new int[n];
	
	for(int i=0;i<n;i++) { 
		*(p+i)=rand()%501+1000;
	}
	
	for(int i=0;i<n;i++) { 
		cout<<*(p+i)<<"  "<<p+i<<endl;
	}
	
	int mayor=0;
	int posmayor;
	for(int i=0;i<n;i++) { 
		if (*(p+i)>mayor){
			mayor=*(p+i);
			posmayor=i;
		}
	}
	
	cout<<mayor<<endl;
	cout<<&p[posmayor]<<endl;
		
	delete []p;
	return 0;
}

