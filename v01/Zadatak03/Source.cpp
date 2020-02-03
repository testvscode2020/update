#include <iostream>
#include "Razlomak.h"

using namespace std;

/*
Definirajte tip podataka za čuvanje podataka o razlomku, 
te na njemu definirajte metode množenja sa cijelim brojem 
te vraćanja tekstualnog prikaza razlomka u formatu 
“brojnik/nazivnik”. Učitavajte od korisnika razlomke i
skalare dok to želi i ispisujte razlomak prije i poslije
množenja sa skalarom. Primjer rada programa:
Upisite brojnik: 4
Upisite nazivnik: 2
Upisite skalar: 7
4/2 * 7 = 28/2
Dalje (1/0): 0
*/

int main() 
{
	int dalje;
	do
	{
		int brojnik;
		cout << "Unesite brojnik:";
		cin >> brojnik;
		int nazivnik;
		cout << "Unesite nazivnik:";
		cin >> nazivnik;

		Razlomak r(brojnik, nazivnik);

		int skalar;
		cout << "Unesite skalar:";
		cin >> skalar;

		cout << r.to_string() << " * " << skalar << " = ";
		r.multiply(skalar);
		cout << r.to_string() << endl;

		cout << "Dalje(1/0):";
		cin >> dalje;
	} while (dalje == 1);

	return 0;
}