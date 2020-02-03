#include <iostream>
#include "RucniMjenjac.h"

using namespace std;

/*
Definirajte tip podataka za čuvanje podataka o ručnom mjenjaču.
Za ručni mjenjač trebate pamtiti trenutno stanje 
(izvan brzine, prva, druga, treća, četvrta, peta) te 
omogućiti sljedeće operacije:
•Promjena brzine prema gore (ako već nije u petoj brzini)
•Promjena brzine prema dolje (ako već nije izvan brzine)
•Ispis trenutne brzine na način:
•Ako je izvan brzine, ispisati: *zzz*
•Ako je u prvoj brzini, ispisati: R
•Ako je u drugoj brzini, ispisati: Rr
•Ako je u trećoj brzini, ispisati: Rrr
•Ako je u četvrtoj brzini, ispisati: Brrrm
•Ako je u petoj brzini, ispisati: Brrrrrrrrrrrrrrrrrm!
*/

int main() 
{
	RucniMjenjac m;
	cout << m.to_string() << endl;
	m.prema_dolje();
	cout << m.to_string() << endl;
	cout << "prema gore:" << endl;
	for (int i = 0; i < 5; i++)
	{
		m.prema_gore();
		cout << m.to_string() << endl;
	}
	cout << "prema dolje:" << endl;
	for (int i = 0; i < 5; i++)
	{
		m.prema_dolje();
		cout << m.to_string() << endl;
	}

	return 0;
}