#include <iostream>
#include "Tocka.cpp"

using namespace std;

/*
Korištenjem struktura, definirati novi tip podataka za čuvanje 
x i y koordinate koja predstavlja točku na ekranu. Unutar 
main-a kreirati točku t, a potom:
•postaviti vrijednosti koordinata i ispisati ih u ovakvom 
obliku t(1, 2)
•postaviti vrijednosti koordinata i ispisati ih: t(-1, 2)
•da li su ovo ispravne koordinate točke na ekranu i hoće li 
ona biti vidljiva, obzirom da je gorna lijeva točka ekrana (0, 0)?
•postoji li bolji način za ispis točke?
•na kratko promijeniti struct deklaraciju u class deklaraciju – 
da li se program može prevesti i zašto?

*/


void print(Tocka t) 
{
	cout << "t(" << t.x << ", " << t.y << ")" << endl;
}

int main() 
{
	Tocka t;
	t.x = 1;
	t.y = 2;

	print(t);

	t.x = -1;
	t.y = 2;

	print(t);

	return 0;
}