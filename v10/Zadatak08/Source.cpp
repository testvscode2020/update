#include <iostream>
#include <fstream>
#include <chrono>
#include "shell_sort.h"
using namespace std;


/*
Učitajte 1.000.000 slučajnih brojeva iz datoteke puno_brojeva1.txt u program.
Ispišite koliko traje njihovo sortiranje shell sortom. Nakon toga, promijenite 
shell sort algoritam tako da umjesto originalne sekvence razmaka koristi Tokudinu
sekvencu iz 1992. Kako se promijenilo vrijeme sortiranja?
•Uputa za rješavanje: sve sekvence koje počinju od 1 se koriste na sljedeći 
način: pomoću formule treba unaprijed izračunati sve elemente sekvence manje
od veličine polja. Nakon toga, te elemente sekvence treba primijeniti na polje,
ali obrnutim redoslijedom. Primjerice, ako imamo polje od 100 elemenata, prvo 
ćemo izračunati Tokudinu sekvencu 1, 4, 9, 20, 46, a zatim ćemo je primijeniti 
na polje, ali počevši od 46 pa sve do 1.
*/

void load(ifstream &in, int *brojevi, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++) 
	{
		in >> brojevi[i];
	}
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


int main() 
{
	ifstream in("puno_brojeva1.txt");
	if (!in) 
	{
		cout << "Greska pri otvaranju datoteke" << endl;
		return 1;
	}

	const int BROJ_ELEMENATA = 1000000;
	int* brojevi = new int[BROJ_ELEMENATA];
	load(in, brojevi, BROJ_ELEMENATA);
	in.close();

	sort_shell(brojevi, BROJ_ELEMENATA);
	
	delete[] brojevi;

	return 0;
}