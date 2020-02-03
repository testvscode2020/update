#include <iostream>
#include "MojVektorNum.h"

using namespace std;

/*
Implementirajte svoj vektor cijelih brojeva koji se može 
koristiti ovako (nema rasta, koristite polje fiksne veličine 100):
MojVektorNum v;
for (int i = 0; i < 10; i++) {
v.push_back((i + 1) * 10);
}
for (MojVektorNum::iterator it = v.begin(); it != v.end(); ++it) {
cout << *it << endl;
}
*/

int main() {
	MojVektorNum v;
	for (int i = 0; i < 10; i++) {
		v.push_back((i + 1) * 10);
	}

	for (MojVektorNum::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}
