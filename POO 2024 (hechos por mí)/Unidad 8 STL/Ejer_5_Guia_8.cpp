#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rand10(){
	return rand()%10;
}

bool es_par(int x) {
	if (x%2==0){
		return true;
	}
}

bool menor_abs(int a, int b){
	if (|a|<|b|) {return true;}
}



int main() {
	vector<int>v(20);
	generate(v.begin(),v.end(),rand10());
	cout<<"Elementos pares: "<<count_if(v.begin(),v.end(),es_par())<<endl;
	sort();
	
	return 0;
}

