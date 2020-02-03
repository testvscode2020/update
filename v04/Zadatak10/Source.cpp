#include <iostream>

#include "MojVektorString.h"

/*
Implementirajte svoj vektor stringova koji se može koristiti 
ovako (omogućite rast primjenom jednostavnog algoritma – ako nema mjesta, 
alocirajte polje veće za 5 elemenata):
void ispisi(MojVektorString& v) {
cout << "s=" << v.size() << ", c=" << v.capacity() << ": ";
for (unsigned i = 0; i < v.size(); i++)
cout << v.at(i);
cout << endl;
}
int main() {
MojVektorString v(5, "-");
ispisi(v);
for (int i = 0; i < 32; i++) {
v.push_back("x");
ispisi(v);
}
return 0;
}
*/


using namespace std;

void ispisi(MojVektorString& v) {
	cout << "s=" << v.size() << ", c=" << v.capacity() << ": ";
	for (unsigned i = 0; i < v.size(); i++)
		cout << v.at(i);
	cout << endl;
}

int main() {
	MojVektorString v(5, "-");
	ispisi(v);
	for (int i = 0; i < 32; i++) {
		v.push_back("x");
		ispisi(v);
	}
	return 0;
}

