//2.a) izbjegavat cemo "Array"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

/*
a) Na osnovu tablice
odaberite strukture koje
je najbolje izbjegavati
ako namjeravamo
ubacivati podatke, a
bavimo se prosječnim
slučajem:
b) Izmjerite i ispišite koliko vremena traje generiranje 100 000
slučajnih godina od 1941 do 1991, zajedno sa izračunom prosječne godine.
*/


int get_random_number(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


int main()
{
	const int n = 100000;
	srand(time(nullptr));
	
	auto begin = high_resolution_clock::now();

	int godine = 0;
	for (unsigned i = 0; i < n; i++)
	{
		godine += get_random_number(1941, 1991);
	}

	double prosjek = godine / n;

	auto end = high_resolution_clock::now();

	cout << "Prosjecna godina je " << prosjek << endl;

	cout << "Potrebno vrijeme: " << duration_cast<milliseconds>(end - begin).count() << "ms" << endl;

	return 0;
}