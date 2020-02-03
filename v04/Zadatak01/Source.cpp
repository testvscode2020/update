#include <iostream>
#include <ctime>
#include <vector>

/*
Odaberite konstruktor i kreirajte vektor cijelih brojeva 
pretpostavljenog (default) kapaciteta. Potom:
•osigurati kapacitet vektora na vrijednost 100
•ubaciti u vektor 100 slučajnih brojeva, tako da se svaki 
od brojeva dodaje na početak, te ispisati brojeve korištenjem at pristupa
•promijeniti veličinu vektora na 50 i korištenjem iteratora ispisati brojeve
•promijeniti kapacitet vektora na 30 i ispisati brojeve iteratorom unazad
•kreirati drugi vektor cijelih brojeva kapaciteta 30, te prvi vektor prekopirati
u drugi u jednoj liniji
•očistite sadržaj prvog vektora (svi elementi odjednom)
•iz drugog vektora izbrišite prvih 10 elemenata te ispišite prvi i posljednji 
element
•iz drugog vektora izbrisati preostale elemente jedan po jedan
*/

int generate_random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	srand(time(nullptr));
	std::vector<int> v;

	// osigurati kapacitet vektora na vrijednost 100
	v.reserve(100);

	// ubaciti u vektor 100 slucajnih brojeva, tako da se svaki od brojeva dodaje na pocetak, 
	//te ispisati brojeve korištenjem at pristupa
	int min = 1;
	int max = 100;
	for (unsigned i = 0; i < v.capacity(); i++) {
		v.insert(v.begin(), generate_random(min, max));
		//paziti na ovo
		//v[i] = generate_random(min, max);
	}

	for (unsigned i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;

	// promijeniti velicinu vektora na 50 i koristenjem iteratora ispisati brojeve
	v.resize(50);
	for (auto it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// promijeniti kapacitet vektora na  30 i ispisati brojeve iteratorom unazad
	v.reserve(30);
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// kreirati drugi vektor cijelih brojeva kapaciteta 30, te prvi vektor prekopirati u drugi u jednoj liniji
	std::vector<int> drugi(30);
	drugi = v;
	//brzi nacin
	//std::vector<int> drugi(v);

	// ocistite sadrzaj prvog vektora(svi elementi odjednom)
	v.clear();

	// iz drugog vektora izbrisite prvih 10 elemenata te ispisite prvi i posljednji element
	drugi.erase(drugi.begin(), drugi.begin() + 10);
	std::cout << drugi.front() << " " << drugi.back() << std::endl;

	// iz drugog vektora izbrisati preostale elemente
	for (auto it = drugi.begin(); it != drugi.end(); ) {
		it = drugi.erase(it);
	}
	std::cout << drugi.size() << std::endl;

	return 0;
}