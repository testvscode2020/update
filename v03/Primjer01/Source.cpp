#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <chrono>

#include "Tocka.h"

using namespace std;

Tocka* prepare_array(int n) 
{
	Tocka* tocke = new Tocka[n];
	for (int i = 0; i < n; i++) 
	{
		cout << "Unos " << i + 1 << ". tocke:" << endl;
		cout << "x:";
		int x;
		cin >> x;
		cout << "y:";
		int y;
		cin >> y;
		tocke[i].init(x, y);
	}
	return tocke;
}

int generate_random(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

int main() 
{
	//primjer 1
	Tocka t;
	cout << "Udaljenost od ishodista default inicijalizacirane tocke:" << t.distance() << endl;
	t.init(100, 90);	
	cout << "Udaljenost od ishodista nakon inicijalizacije:" << t.distance() << endl;

	//primjer 2
	int n = 5; 
	Tocka* tocke = prepare_array(n);
	for (int i = 0; i < n; i++) 
	{
		cout << "Udaljenost tocke " << i + 1 << " od ishodista:" << tocke[i].distance() << endl;
	}
	delete[] tocke;

	//primjer 3
	srand(time(nullptr));
    int min = 100;
    int max = 200;
    int rnd = generate_random(100, 200);
	cout << "Slucajni broj: " << rnd << endl;

	//primjer 4
	auto begin = chrono::high_resolution_clock::now();
	for (int i = 1; i <= 10; i++) 
	{
		for (int j = 1; j <= 10; j++) 
		{
			cout << "\t" << i * j;
		}
		cout << endl;
	}
	auto end = chrono::high_resolution_clock::now();
	cout 
		<< "Potrebno vrijeme:" 
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;

	//primjer 5
	ifstream in("Broj_znanstvenika_na_milijun_stanovnika.csv");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	//ignoriranje prva 2. reda i hvatanje 3. reda -> Albania
	string line;
	for (int i = 0; i < 3; i++) 
	{
		getline(in, line);
	}

	in.close();

	//koristenje stringstreama za parsiranje stringa
	stringstream ss(line);
	string br_znanstvenika;
	//ignoriranje prve 4. kolone i hvatanje 5. kolone -> 2008
	for (int i = 0; i < 5; i++) 
	{
		getline(ss, br_znanstvenika, ';');
	}

	//koristenje stringstreama za pretvaranje string u int
	stringstream converter;
	converter << br_znanstvenika;
	int broj;
	if (converter >> broj) 
	{
		cout << "Broj znanstvenika u Albaniji za 2008. godinu: " << broj << endl;
	}
	else
	{
		cout << "Broj znanstvenika u Albaniji za 2008. godinu nije definiran"<< endl;
	}

	return 0;
}