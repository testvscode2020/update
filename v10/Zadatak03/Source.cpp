#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <functional>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"

using namespace std;

/*
Promijenite prethodni zadatak tako da koristite prvih 20.000 brojeva iz 
datoteke puno_brojeva2.txt (brojevi su već sortirani kako treba – najbolji
mogući slučaj).
*/


void load(ifstream &in, int *originalni_brojevi, int *radno_polje, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		in >> originalni_brojevi[i];
		radno_polje[i] = originalni_brojevi[i];
	}
}

void copy_array(int* originalni_brojevi, int* radno_polje, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		radno_polje[i] = originalni_brojevi[i];
	}
}

void sort(int *radno_polje, const int BROJ_ELEMENATA, string tekst, function<void(int*, int)> funkcija)
{
	auto begin = chrono::high_resolution_clock::now();
	funkcija(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< tekst
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

int main()
{
	ifstream in("puno_brojeva2.txt");
	if (!in)
	{
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 20000;

	int* originalni_brojevi = new int[BROJ_ELEMENATA];
	int* radno_polje = new  int[BROJ_ELEMENATA];

	load(in, originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	in.close();

	// Bubble sort.
	sort(radno_polje, BROJ_ELEMENATA, "Bubble sort:", bubble_sort);

	// Selection sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort(radno_polje, BROJ_ELEMENATA, "Selection sort:", selection_sort);

	// Insertion sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort(radno_polje, BROJ_ELEMENATA, "Insertion sort:", insertion_sort);

	// Shell sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort(radno_polje, BROJ_ELEMENATA, "Shell sort:", shell_sort);

	//Merge sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort(radno_polje, BROJ_ELEMENATA, "Merge sort:", merge_sort);

	delete[] originalni_brojevi;
	delete[] radno_polje;

	return 0;
}