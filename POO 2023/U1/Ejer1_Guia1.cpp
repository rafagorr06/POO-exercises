#include <iostream>
using namespace std;

int main() {
	int x=10;
	int *p = new int;
	cin>>*p;
	cout<<&x<<' '<<p<<endl;
	delete p;
	return 0;
}

