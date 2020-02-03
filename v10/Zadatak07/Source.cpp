#include <iostream>
#include <fstream>
#include <chrono>
#include "quick_sort.h"

using namespace std;

/*
Iz datoteka puno_brojeva1.txt i puno_brojeva2.txt učitajte brojeve u dva polja
(u svakoj datoteci ima točno milijun brojeva). Primijenite quick sort na svako 
polje i ispišite koliko je sortiranje trajalo. Koju datoteku sortira dulje i zašto?
•Promijenite zadatak tako da umjesto Debug konfiguracije koristite 
Release konfiguraciju ( ). Kakva su sada vremena sortiranja i kako to 
tumačite? Vratite natrag na Debug konfiguraciju.
*/

int* load(ifstream& dat, const int BROJ_ELEMENATA) 
{
	int* polje = new int[BROJ_ELEMENATA];
	for (int i = 0; i < BROJ_ELEMENATA; i++) 
	{
		dat >> polje[i];
	}
	return polje;
}

void sort_quick(int *radno_polje, const int BROJ_ELEMENATA)
{
	auto begin = chrono::high_resolution_clock::now();
	quick_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Quick sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

int main() 
{
	ifstream in1("puno_brojeva1.txt");
	ifstream in2("puno_brojeva2.txt");
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

	cout << "Slucajni raspored brojeva:" << endl;
	sort_quick(brojevi1, BROJ_ELEMENATA);

	cout << "Sortirani brojevi:" << endl;
	sort_quick(brojevi2, BROJ_ELEMENATA);

	delete[] brojevi1;
	delete[] brojevi2;

	return 0;
}