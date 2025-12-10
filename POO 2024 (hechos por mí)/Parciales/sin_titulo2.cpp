#include <iostream>
#include <fstream>
using namespace std;

class TDP {
public:
	TDP (string nombrejuego) : m_nombre(nombrejuego) {}
	ifstream archi(nombrejuego)
private:
		string m_nombre;
};

int main() {
	
	return 0;
}

