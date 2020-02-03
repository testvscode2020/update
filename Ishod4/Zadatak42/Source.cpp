#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

//42. ti je identican kao vjezbe 11, zadatak 10
//Kreiraj vektor razbacanih br. od 100 do 200 i opitaj korisnika koji broj zeli traziti, pa mu ispisi ima li tog broja ili nema.
//Bodovi ovise optimizaciji

void pripremi_vektor(vector<int> &v) {

	for (int i = 100; i <= 200; i++) 
	{
		v.push_back(i); //napravis vektor od 100 do 200
	}

	random_shuffle(v.begin(), v.end()); //pa razbacas brojeve
}

void pretrazi(vector<int> &v) {

	bool dalje;

	do
	{
		system("cls");
		int broj;
		cout << " Odaberi jedan broj: "; //sigurno ces pogrijesiti, hihihihi...
		cin >> broj;

		if (binary_search(v.begin(), v.end(), broj)) //najoptimalnije moguce rjesenje, binary_search
		{
			cout << " IMA!" << endl;
		}
		else
		{
			cout << " NEMA!" << endl;
		}

		cout << " Dalje? (1/0) : ";
		cin >> dalje;

	} while (dalje);
}

int main() {

	srand(time(0));
	vector<int> v;
	pripremi_vektor(v);

	sort(v.begin(), v.end()); //obavezno sortiras inace nece raditi

	pretrazi(v);

	return 0;
}