#include <iostream>

using namespace std;

/*
Napišite program koji korisniku omogućuje sljedeće matematičke 
operacije (svaku napravite u posebnoj funkciji):
•Množenje
•Dijeljenje – osigurati da djeljitelj ne smije biti 0
•Vađenje drugog korijena – osigurati da broj ne smije biti < 0
Učitajte od korisnika operaciju i potrebne operande pa izvršite 
operaciju i ispišite rezultat. Kakav god korisnikov unos bio, 
program se ne smije srušiti! Koristite ili tradicionalni ili 
moderni način upravljanja pogreškama.
*/

int multiply(int a, int b) 
{
	return a * b;
}

int divide(int a, int b) 
{
	//cjelobrojno dijeljenje s 0 nije greska u standardnom C++ pa bacamo grešku rucno
	if (b == 0)
	{
		throw runtime_error("Djeljitelj ne smije biti 0");
	}
	return a / b;
}

int square_root(int a) 
{
	//korijen negativnog broja ne baca gresku pa cinimo to rucno
	if (a < 0)
	{
		throw exception("Broj ne smije biti manji od 0");
	}
	return sqrt(a);
}

int main() 
{
	int a;
	cout << "Unesite prvi broj:";
	cin >> a;

	int b;
	cout << "Unesite drugi broj:";
	cin >> b;

	cout << a << " * " << b << " = " << multiply(a, b) << endl;
	//hvatamo vlastito bacenu gresku
	try
	{
		cout << a << " / " << b << " = " << divide(a, b) << endl;
	}
	catch (const exception& e)
	{
		cout << "Pogreska: " << e.what() << endl;
	}

	try
	{
		cout << "sqrt(" << a << ") = " << square_root(a) << endl;
	}
	catch (const exception& e)
	{
		cout << "Pogreska: " << e.what() << endl;
	}

	return 0;
}