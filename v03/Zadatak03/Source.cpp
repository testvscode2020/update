﻿#include <iostream>
#include <ctime>
#include "Student.h"

using namespace std;

/*
Definirajte tip podataka za čuvanje podataka o studentima. 
Za svakog studenta čuvajte ime, prezime te godinu rođenja. 
Kreirajte polje od tri studenta; imena i prezimena učitajte 
od korisnika, a za vrijednost godine rođenja stavite slučajnu
vrijednost između 1961. i 1997.
*/

int generate_random(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

void kreiraj_studente(student* polje, int n) 
{
	srand(time(nullptr));
	for (int i = 0; i < n; i++) 
	{
		cout << "Unesite ime " << i + 1 << ". studenta:";
		string ime;
		getline(cin, ime);
		cout << "Unesite prezime " << i + 1 << ". studenta:";
		string prezime;
		getline(cin, prezime);
		int god_rodjenja = generate_random(1961, 1997);
		polje[i].init(ime, prezime, god_rodjenja);
	}
}

int main() 
{

	student polje[5];
	kreiraj_studente(polje, sizeof(polje) / sizeof(student));
	for (int i = 0; i < sizeof(polje) / sizeof(student); i++) 
	{
		cout << polje[i].to_string() << endl;
	}

	return 0;
}