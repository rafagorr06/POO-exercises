#include <iostream>
using namespace std;

int main() {
	
	int a=90;
	int *p=&a;
	int b=(*p)++;
	int *q=p+2;
	
	cout<<p<<" "<<*p<<" ";
	cout<<endl;
	cout<<q<<" "<<*q<<" ";
	
	cout<<endl;
	cout<<endl;
	
	a= *(q++); b=*(++p);
	(*p)++;
	
	cout<<p<<" "<<&p<<" ";
	cout<<endl;
	cout<<q<<" "<<&q<<" ";
	
	delete p;
	delete q;
	return 0;
}

