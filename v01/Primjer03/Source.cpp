#include <iostream>
#include "Tocka.h"
#include "Tocka.h"

using namespace std;

/*
Prethodni primjer prepraviti razdvajanjem klase na 
zaglavlje i implementaciju. Spriječiti mogućnost 
dvostrukog uključivanja zaglavlja i demonstrirati.
*/

int main() 
{

	Tocka t1(1, 2);
	cout << t1.to_string() << endl;

	t1.set_x(-1);
	cout << t1.to_string() << endl;

	Tocka t2;
	cout << t2.to_string() << endl;

	t2.set_x(10);
	t2.set_y(8);
	cout << t2.to_string() << endl;

	cout << "distance t1: " << t1.distance() << endl;
	cout << "distance t2: " << t2.distance() << endl;

	return 0;
}