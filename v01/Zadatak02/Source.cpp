﻿#include <iostream>
#include <fstream>

#include "Pravokutnik.h"

using namespace std;

/*
Definirajte tip podataka za čuvanje širina i visina pravokutnika.
U mainu kreirajte polje od 5 pravokutnika, kroz novu funkciju 
učitajte vrijednosti od korisnika, te njihove površine pomoću 
druge funkcije ispišite u tekstualnu datoteku. Format ispisa 
treba biti (svaki pravokutnik u svoj redak):
P(širina, visina) = površina
Otvaranje i zatvaranje datoteke radite u main-u.
*/

void input(Pravokutnik *polje, int length) 
{
	for (unsigned int i = 0; i < length; i++)
	{
		cout << "unos " << i + 1 << ". pravokutnika:" << endl;
		double sirina;
		cout << "sirina:";
		cin >> sirina;
		polje[i].set_sirina(sirina);
		double visina;
		cout << "visina:";
		cin >> visina;
		polje[i].set_visina(visina);
	}
}

void output(Pravokutnik *polje, int length, ofstream &out) 
{
	for (unsigned int i = 0; i < length; i++)
	{
		out << polje[i].to_string() << endl;
	}

}

int main() 
{
	Pravokutnik polje[5];
	int length = sizeof(polje) / sizeof(Pravokutnik);
	input(polje, length);

	ofstream out("pravokutnici.txt");
	if (!out) {
		cout << "nije moguce kreirati datoteku" << endl;
		return 1;
	}

	output(polje, length, out);

	out.close();
	return 0;
}