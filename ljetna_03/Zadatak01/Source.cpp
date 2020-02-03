#include <iostream>

#include "Proizvod.h"

using namespace std;

/*
Definirati novi tip podataka za čuvanje podataka o proizvodu
(šifra, naziv, broj komada, rok trajanja u mjesecima) 
uz sljedeće uvjete:
•Nije dopušteno kreirati Proizvod bez šifre, naziva i broja komada
•Pri kreiranju osobe, upis roka trajanja je opcionalan 
(ako se ne upiše, predodređena vrijednost je 12 mjeseci)
•Na tipu postoji metoda koja vraća tekst u formatu 
“šifra – naziv, broj, rok”
•Na tipu postoji metoda koja omogućuje naknadno upisivanje 
roka trajanja
•Na tipu postoji metoda koja omogućuje čitanje broja komada


*/

int main()
{
	Proizvod p1("123", "Lopta", 100);
	cout << p1.to_string() << endl;

	Proizvod p2("321", "Reket", 20, 22);
	cout << p2.to_string() << endl;

	return 0;
}