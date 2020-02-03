#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Tocka3d.h"

/*
Kreirajte vektor trodimenzionalnih točaka. Iz datoteke „tocke.txt” 
je potrebno je učitati sve točke u vektor. Nužno je izbjeći kreiranje 
nepotrebnih objekata.
*/

void print(Tocka3d &t) {
	std::cout << "T(" << t.x << ", " << t.y << ", " << t.z << ");" << std::endl;
}

int main() {
	std::vector<Tocka3d> tocke;

	std::ifstream in("tocke.txt");
	if (!in) {
		std::cout << "Greska pri otvaranju tocke.txt" << std::endl;
		return 1;
	}

	int x, y, z;
	while(true) {
		if (!(in >> x)) {
			break;
		}
		in >> y;
		in >> z;
		//tocke.emplace(tocke.end(), x, y, z);
		tocke.emplace_back(x, y, z);
	}

	in.close();

	//provjera
	std::for_each(tocke.begin(), tocke.end(), print);

	return 0;
}