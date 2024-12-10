#include <iostream>
using namespace std;

/*
int && a;     
significa que "a" es una referencia de valor r.
&& normalmente solo se usa para declarar un par�metro de una funci�n. 
Y solo se necesita una expresi�n de valor r.
	
En pocas palabras, un valor r es un valor que no tiene una direcci�n de memoria.
Por ejemplo, el n�mero 6 y el car�cter 'v' son valores r. 
int a, a es un valor l, sin embargo (a + 2) es un valor r.
*/


void foo(int&& a)
{
	//Some magical code...
}
int main()
{
	int b;
//	foo(b);       //Error. An rValue reference cannot be pointed to a lValue.
	foo(5);       //Compiles with no error.
	foo(b+3);     //Compiles with no error.
	//int&& c = b;  //Error. An rValue reference cannot be pointed to a lValue.
	int&& d = 5;  //Compiles with no error.
	
	cout<<d;
	return 0;
}

