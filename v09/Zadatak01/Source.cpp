#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

/*
Napravite vektor od 10 slučajnih brojeva između 1 i 100 i onda:
a. Ispišite sve brojeve.
b. Uredite vektor tako da ima svojstva hrpe (funkcija make_heap) pa
ispišite sve brojeve.
c. Učitavajte od korisnika brojeve dok on to želi. Svaki učitani broj dodajte
u vektor te osigurajte da je vektor i dalje uređen kao hrpa (funkcija
push_heap).
d. Kad korisnik više ne želi učitavati brojeve, ispišite brojeve iz vektora.
e. Uklonite sve brojeve iz hrpe koristeći funkciju pop_heap (i ostalo što
vam treba). Nakon svakog uklonjenog broja ispišite sadržaj hrpe.
*/


int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

vector<int> fill_numbers(unsigned n, int min, int max)
{
	srand(time(nullptr));
	vector<int> v;
	for (unsigned i = 0; i < n; i++)
	{
		v.push_back(generate_random(min, max));
	}
	return v;
}

void print(vector<int> &v)
{
	for (int n : v)
	{
		cout << n << " ";
	}
	cout << endl;
}

void insert(vector<int> &v)
{
	bool dalje;
	int n;
	do
	{
		cout << "Unesite broj: ";
		cin >> n;
		v.push_back(n);
		push_heap(v.begin(), v.end());
		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);
}

int main() 
{
	vector<int> numbers = fill_numbers(10, 1, 100);

	cout << "vektor: ";
	print(numbers);
	
	make_heap(numbers.begin(), numbers.end());
	cout << "vektor kao hrpa: ";
	print(numbers);

	insert(numbers);
	cout << "vektor nakon inserta: ";
	print(numbers);

	while (!numbers.empty())
	{
		cout << numbers.front() << " - ";
		pop_heap(numbers.begin(), numbers.end());
		numbers.pop_back();
		print(numbers);
	}

	return 0;
}