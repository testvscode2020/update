#include <iostream>
#include "MojVektor.h"

using namespace std;

/*
Implementirajte svoj vektor stringova. Vektor ne treba moći rasti
već možete koristiti polje veličine 50. Vektor treba moći koristiti
na sljedeći način:
MojVektor v(10, "HELLOOOO");
for (unsigned i = 0; i < v.size(); i++) {
cout << v.at(i) << endl;
}
*/

int main() {

	MojVektor v(10, "HELLOOOO");
	for (unsigned i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}

	return 0;
}