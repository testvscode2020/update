#include <iostream>
#include "MojVektorChar.h"

using namespace std;

/*
Implementirajte svoj vektor charova. Vektor ne treba moći rasti 
već možete koristiti polje fiksne veličine 10. Pretpostavimo da 
će svaki push_back() uspjeti (tj. ne treba provjeravati ima li 
još mjesta u polju). Vektor treba moći koristiti na sljedeći način:
MojVektorChar v;
v.push_back('a');
for (unsigned i = 0; i < v.size(); i++)
cout << v.at(i) << endl;
v.push_back('b');
for (unsigned i = 0; i < v.size(); i++)
cout << v.at(i) << endl;
v.push_back('c');
for (unsigned i = 0; i < v.size(); i++)
cout << v.at(i) << endl;
*/

int main() {

	MojVektorChar v;

	v.push_back('a');
	for (unsigned i = 0; i < v.size(); i++)
		cout << v.at(i) << endl;

	v.push_back('b');
	for (unsigned i = 0; i < v.size(); i++)
		cout << v.at(i) << endl;
	
	v.push_back('c');
	for (unsigned i = 0; i < v.size(); i++)
		cout << v.at(i) << endl;

	return 0;
}