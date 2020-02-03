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
Učitajte prvih 20.000 slučajnih brojeva iz datoteke puno_brojeva1.txt u program.
Primijenite bubble, insertion, selection, shell i merge iz priloga na brojeve 
iz datoteke i ispišite za svaki koliko je trajao.
*/

void load(ifstream &in, int *originalni_brojevi, int *radno_polje, const int BROJ_ELEMENATA)
{
	int temp;
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		in >> temp;
		originalni_brojevi[i] = temp;
		radno_polje[i] = temp;
	}
}

void copy_array(int* originalni_brojevi, int* radno_polje, const int BROJ_ELEMENATA) 
{
	for (int i = 0; i < BROJ_ELEMENATA; i++) 
	{
		radno_polje[i] = originalni_brojevi[i];
	}
}

void sort_bubble(int *radno_polje, const int BROJ_ELEMENATA) 
{
	auto begin = chrono::high_resolution_clock::now();
	bubble_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Bubble sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

void sort_selection(int *radno_polje, const int BROJ_ELEMENATA) 
{
	auto begin = chrono::high_resolution_clock::now();
	selection_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Selection sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

void sort_insertion(int *radno_polje, const int BROJ_ELEMENATA) 
{
	auto begin = chrono::high_resolution_clock::now();
	insertion_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Insertion sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

void sort_shell(int *radno_polje, const int BROJ_ELEMENATA) 
{
	auto begin = chrono::high_resolution_clock::now();
	shell_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Shell sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

void sort_merge(int *radno_polje, const int BROJ_ELEMENATA) 
{
	auto begin = chrono::high_resolution_clock::now();
	merge_sort(radno_polje, BROJ_ELEMENATA);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Merge sort:"
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

//napredni primjer slanja funkcije u funkciju - takvo koristenje funkcija ne ulazi u ishode
//umjesto da imamo mnogo gotovo identicnih funkcija, mozemo parametrizirati funkciju da prima funkciju
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
	ifstream in("puno_brojeva1.txt");
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
	sort_bubble(radno_polje, BROJ_ELEMENATA);
	//sort(radno_polje, BROJ_ELEMENATA, "Bubble sort:", bubble_sort);

	// Selection sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort_selection(radno_polje, BROJ_ELEMENATA);
	//sort(radno_polje, BROJ_ELEMENATA, "Selection sort:", selection_sort);

	// Insertion sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort_insertion(radno_polje, BROJ_ELEMENATA);
	//sort(radno_polje, BROJ_ELEMENATA, "Insertion sort:", insertion_sort);

	// Shell sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort_shell(radno_polje, BROJ_ELEMENATA);
	//sort(radno_polje, BROJ_ELEMENATA, "Shell sort:", shell_sort);

	//Merge sort.
	copy_array(originalni_brojevi, radno_polje, BROJ_ELEMENATA);
	sort_merge(radno_polje, BROJ_ELEMENATA);
	//sort(radno_polje, BROJ_ELEMENATA, "Merge sort:", merge_sort);

	delete[] originalni_brojevi;
	delete[] radno_polje;

	return 0;
}