#include <iostream>
using namespace std;

int main() {
	int n=10;
	cout<<&n<<endl;
	cout<<"----------------"<<endl;
	int *p = new int;
	int m;
	cin>>m;
	cout<<&p<<endl;
	delete p;
	return 0;
}
//No siempre es la misma posicion

