#include <iostream>
using namespace std;


template <typename T>
T clamp(T &x, T max, T min) {
	if (x>max) {x=max;};
	if (x<min) {x=min;}
	return x;
}
int main() {
	float a=0.5;
	cout<<clamp(a,0.0f,1.0f)<<endl;
	return 0;
}

