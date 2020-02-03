#include <iostream>
#include "Tocka.cpp"

using namespace std;

/*
Prethodni primjer riješiti korištenjem klasa:
•Definirati konstruktor koji prima potrebne vrijednosti
za inicijalizaciju
•može li se sada točka inicijalizirati default konstruktorom,
bez parametara? •Kreirati metode pristupa x i y varijablama. 
Ako pozivatelj pokuša postaviti vrijednost koordinate na negativnu 
vrijednost, vrijednost koordinate postaje 0
•istu logiku primijeniti u konstruktoru
•da li je moguće izbjeći redundanciju u kodu?
•Definirati konstruktor koji ne prima vrijednosti već vrijednosti 
koordinata postavlja na ishodište ekrana t(0,0)
•Kreirati metodu to_string() koja vraća točku u string formatu t(x, y)
•Kreirati metodu koja izračunava udaljenost točke od ishodišta ekrana
•Demonstrirati sve funkcionalnosti
*/

int main() 
{
	Tocka t1(1, 2);
	cout << t1.to_string() << endl;
	
	t1.set_x(-1);
	cout << t1.to_string() << endl;

	Tocka t2;
	cout << t2.to_string() << endl;

	t2.set_x(10);
	t2.set_y(8);
	cout << t2.to_string() << endl;

	cout << "distance t1: " << t1.distance() << endl;
	cout << "distance t2: " << t2.distance() << endl;

	return 0;
}