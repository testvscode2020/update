#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Drzava.h"

/*
Napravite tip podataka koji će omogućavati čuvanje 
podataka o nazivu države te više podataka o broju 
znanstvenika na milijun stanovnika. Definirajte i 
operaciju koja vraća prosječni broj znanstvenika na
milijun stanovnika za sve unesene godine.
Iz datoteke Broj_znanstvenika_na_milijun_stanovnika.csv 
učitajte sve podatke, te nakon toga ispišite prosjeke 
broja znanstvenika na milijun stanovnika za sve unesene 
države (ignorirajte godine u kojima nema upisanog broja).
*/

using namespace std;

void load(ifstream &in, vector<Drzava> &drzave)
{
	string line;
	getline(in, line);
	while (getline(in, line)) 
	{
		//cout << line << endl;
		stringstream ss(line);
		string naziv;
		getline(ss, naziv, ';');
		Drzava d(naziv);

		string temp;
		while (getline(ss, temp, ';')) 
		{
			stringstream c(temp);
			int n;
			if (c >> n) 
			{
				d.dodaj_broj_znanstvenika(n);
			}
		}
		drzave.push_back(d);
	}
}

void print(Drzava drzava)
{
	cout << drzava.get_naziv() << " - " << drzava.prosjecan_broj_znanstvenika() << endl;
}

int main() 
{
	ifstream in("Broj_znanstvenika_na_milijun_stanovnika.csv");
	if (!in) 
	{
		cout << "nije moguce pristupiti datoteci" << endl;
		return 1;
	}
	vector<Drzava> drzave;
	load(in, drzave);

	in.close();

	for_each(drzave.begin(), drzave.end(), print);

	return 0;
}
