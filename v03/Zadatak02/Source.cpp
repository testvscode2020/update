#include <iostream>
#include <ctime>
#include <chrono>

#include "funkcije_za_sortiranje.h"

/*
U prilogu su dva gotova algoritma sortiranja implementirana pomoću dvije funkcije: bubble_sort i quick_sort. Pripremite si
a.1.000
b.10.000
c.20.000
slučajnih brojeva između 1 i 1000. 
Sortirajte dobivene brojeve prvo pomoću quick sorta, 
a zatim iste brojeve pomoću bubble sorta. Ispišite u 
konzolu koliko je izvođenje svakog algoritma trajalo.
*/

using namespace std;

int generate_random(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

int* prepare_array(int n) 
{
    srand(time(nullptr));
	int* polje = new int[n];
	for (int i = 0; i < n; i++) 
	{
		polje[i] = generate_random(1, 1000);
	}
	return polje;
}

int* copy_array(int *polje, int n) 
{
	int* kopija = new int[n];
	for (int i = 0; i < n; i++) 
	{
		kopija[i] = polje[i];
	}
	return kopija;
}

int main() 
{
	int n = 1000;
	//n = 10000;
	//n = 20000;

	int* brojevi1 = prepare_array(n);
	int* brojevi2 = copy_array(brojevi1, n);

	auto begin = chrono::high_resolution_clock::now();
    quick_sort(brojevi1, n);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Quick sort:"
		<< chrono::duration_cast<chrono::microseconds>(end - begin).count()
		<< " us" << endl;

	begin = chrono::high_resolution_clock::now();
	bubble_sort(brojevi2, n);
	end = chrono::high_resolution_clock::now();
	cout
		<< "Bubble sort:"
		<< chrono::duration_cast<chrono::microseconds>(end - begin).count()
		<< " us" << endl;

	delete[] brojevi1;
	delete[] brojevi2;

	return 0;
}