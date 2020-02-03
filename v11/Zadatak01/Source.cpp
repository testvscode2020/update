#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "counting_sort.h"

using namespace std;

/*
Iz datoteka puno_malih_brojeva1.txt i puno_malih_brojeva2.txt učitajte 
brojeve u dva polja (u svakoj datoteci ima točno milijun brojeva, a
razlikuju se samo po prvom broju). Primijenite counting sort na svako 
polje i ispišite koliko je sortiranje trajalo. Koju datoteku sortira 
dulje i zašto?
*/

int* load(ifstream& in, const int BROJ_ELEMENATA) 
{
	int* polje = new int[BROJ_ELEMENATA];
	for (int i = 0; i < BROJ_ELEMENATA; i++) 
	{
		in >> polje[i];
	}
	return polje;
}

void sort_counting(int *brojevi, const int BROJ_ELEMENATA, string tekst) 
{
	auto start = chrono::high_resolution_clock::now();
	counting_sort(brojevi, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< tekst
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
}

int main() 
{
	ifstream in1("puno_malih_brojeva1.txt");
	ifstream in2("puno_malih_brojeva2.txt");
	if (!in1 || !in2) 
	{
		cout << "Greska pri otvaranju datoteka" << endl;
		return 1;
	}

	const int BROJ_ELEMENATA = 1000000;
	int* brojevi1 = load(in1, BROJ_ELEMENATA);
	int* brojevi2 = load(in2, BROJ_ELEMENATA);

	in1.close();
	in2.close();

	sort_counting(brojevi1, BROJ_ELEMENATA, "brojevi1: ");
	sort_counting(brojevi2, BROJ_ELEMENATA, "brojevi2: ");

	delete[] brojevi1;
	delete[] brojevi2;

	return 0;
}