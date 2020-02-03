#include <iostream>
#include <fstream>
#include "pravokutnik.h"
#include "merge_sort.h"

using namespace std;

/*
Na raspolaganju su vam Selection sort i Merge sort (u prilozima).
Koristeći podatke sa slike 1, od ta dva algoritma odaberite onaj
koji ima bolju složenost u najgorem slučaju. Promijenite odabrani
algoritam tako da sortira pravokutnike (širina, visina) rastuće
prema površini. Učitajte svih 1000 pravokutnika iz datoteke
pravokutnici.txt (u svakom retku su širina i visina jednog
pravokutnika odvojeni razmakom) i prepišite ih u drugu datoteku,
ali sortirano rastuće.
*/

void load(ifstream &in, pravokutnik *pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++) 
	{
		in >> pravokutnici[i].a >> pravokutnici[i].b;
	}
}

void write(ofstream &out, pravokutnik *pravokutnici, const int BROJ_ELEMENATA)
{
	for (int i = 0; i < BROJ_ELEMENATA; i++)
	{
		out << pravokutnici[i].a << " " << pravokutnici[i].b << endl;
	}

}
int main()
{
	ifstream in("pravokutnici.txt");
	ofstream out("pravokutnici_rastuce.txt");
	if (!in || !out)
	{
		cout << "Greska pri pristupu datotekama" << endl;
		return 1;
	}
	const int BROJ_ELEMENATA = 1000;

	pravokutnik* pravokutnici = new pravokutnik[BROJ_ELEMENATA];
	load(in, pravokutnici, BROJ_ELEMENATA);
	in.close();

	merge_sort(pravokutnici, BROJ_ELEMENATA);

	write(out, pravokutnici, BROJ_ELEMENATA);

	out.close();
	delete[] pravokutnici;

}