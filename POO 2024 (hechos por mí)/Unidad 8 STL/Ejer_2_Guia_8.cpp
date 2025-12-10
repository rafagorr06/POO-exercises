#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
vector<T> dosmayores_up(vector<T>&v) {
	T max = *max_element(v.begin(),v.end());
	swap(v[0],max);
	T max2=*max_element(v.begin()+1,v.end());
	swap (v[1],max2);
	return v;
}


int main() {
	vector<int>v(5);
	for(size_t i=0;i<v.size();i++) { 
		int valor;
		cout<<"Ingrese valor:"<<endl;
		cin>>valor;
		v[i]=valor;
	}
	cout<< " " <<endl;
	dosmayores_up(v);
	for(size_t i=0;i<v.size();i++) { 
		cout<<v[i]<<endl;
	}
	return 0;
}

