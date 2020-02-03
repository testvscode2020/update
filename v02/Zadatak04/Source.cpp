#include <iostream>

#include "Pravokutnik.h"

using namespace std;

/*
Definirajte tip podataka za čuvanje podataka o pravokutnicima. 
Korisniku omogućite samo kreiranje pravokutnika s 
ispravnom širinom i visinom (mora biti veća od 0). 
Omogućite korisniku da pozivajući metodu na objektu 
može dobiti string u kojem je nacrtan pravokutnik. 
Neka metoda prima parametre koji odlučuju kako će 
pravokutnik biti nacrtan:
•Znak kojim će biti iscrtan rub pravokutnika
•Znak kojim će biti iscrtan sadržaj pravokutnika
•Treba li iscrtati sadržaj pravokutnika ili ne
*/

int main() 
{
	try
	{
		//Pravokutnik p(-5, 8);
		//Pravokutnik p(5, -8);
		Pravokutnik p(5, 8);

		cout << p.shape('x', '-', true);
		cout << endl;
		cout << p.shape('x', '-', false);
	}
	catch (const exception &e)
	{
		cout << "Pogreska: " << e.what() << endl;
	}

	return 0;
}