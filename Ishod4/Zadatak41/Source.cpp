#include <iostream>
#include <fstream>
#include "merge_sort.h"
#include "Racuni.h" //povuce string i std iz headera

//zadatak 41 ti je kao i prvi zadatk u dopunskoj 7(mislim)
//dobijes tablicu, prepoznas da je merge sort i dalje samo ides kao i na dopunskoj
//jedino ti je umjesto pravokutnika iznos i br. racuna (int i string) umjesto 2 inta

void load(ifstream &in, Racuni* polje, int length) {

	for (int i = 0; i < length; i++)
	{
		in >> polje[i].iznos >> polje[i].broj_racuna; //iznos pa racun ili obrnuto, pise u zadatku
	}
}

void write(ofstream &out, Racuni* polje, int length) {

	for (int i = 0; i < length; i++)
	{
		out << polje[i].iznos << " " << polje[i].broj_racuna << endl;
	}
}

int main() {

	ifstream in("Racuni.csv"); //u ispitu ce bit racuni.csv, ja sam ovdje uzeo iz materijala za dodatnu 5
	ofstream out("output.txt"); //ispis u drugu datoteku
	if (!in) {

		cout << " Error 404 File Not Found! " << endl;
		return 1;
	}

	const int N = 1000; //recimo da trazi 1000 racuna, ne sjecam se tocno
	Racuni* polje = new Racuni[N];
	
	load(in, polje, N); //ucitaj u polje
	in.close();

	merge_sort(polje, N); //primjeni merge sort

	write(out, polje, N); //ispisi u out datoteku
	delete[] polje; //obavezno oslobodi polje!!!

	return 0;
}