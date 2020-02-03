#include "Drzava.h"

Drzava::Drzava(string naziv)
{
	this->naziv = naziv;
}

void Drzava::dodaj_broj_znanstvenika(int n)
{
	broj_znanstvenika.push_back(n);
}

string Drzava::get_naziv()
{
	return naziv;
}

double Drzava::prosjecan_broj_znanstvenika()
{
	if (broj_znanstvenika.size() == 0) 
	{
		return 0;
	}
	double suma = 0;
	for (auto it = broj_znanstvenika.begin(); it != broj_znanstvenika.end(); ++it) 
	{
		suma += *it;
	}
	return suma / broj_znanstvenika.size();
}
