#include <iostream>
#include <vector>
#include <chrono>

/*
Izmjerite i ispišite koliko traje ubacivanje 100.000 
cijelih brojeva (1 po 1) na početak vektora, a koliko na kraj.
*/

using namespace std;
//sub-namespace
using namespace std::chrono;

int main() {

	std::vector<int> v1;
	std::vector<int> v2;

	unsigned n = 100000;

	// Ubacivanje na kraj:
	auto begin = high_resolution_clock::now();
	for (unsigned i = 0; i < n; i++) {
		v1.push_back(i);
	}
	auto end = high_resolution_clock::now();
	std::cout 
		<< "Ubacivanje na kraj je trajalo " 
		<<  duration_cast<milliseconds>(end - begin).count() 
		<< " ms" 
		<< std::endl;

	// Ubacivanje na pocetak:
	begin = high_resolution_clock::now();
	for (unsigned i = 0; i < n; i++) {
		v2.insert(v2.begin(), i);
	}
	end = high_resolution_clock::now();
	std::cout
		<< "Ubacivanje na pocetak je trajalo "
		<< duration_cast<milliseconds>(end - begin).count()
		<< " ms"
		<< std::endl;

	return 0;
}
