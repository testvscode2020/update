#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "hash_table.h"

using namespace std;

/*
Promijenite prethodni zadatak tako da koristite hash funkciju h(key)
= key mod 100003 (prosti broj otprilike 10 puta manji od broja
ključeva) i optimizirate veličinu polja. Konflikte nemojte razrješavati
već samo pregazite staru vrijednost. Na kraju ispišite koliko
konflikata se dogodilo.
*/

void prepare_vector(vector<int> &v, int n)
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void load_table(hash_table &table, int n, vector<int> &v)
{
	for (int i = 0; i < n; i++) 
	{
		table.insert(v[i], v[i] * v[i]);
	}
}

int main() 
{
	srand(unsigned(time(nullptr)));

	vector<int> v;
	const unsigned BROJ_ELEMENATA = 1000000;
	prepare_vector(v, BROJ_ELEMENATA);

	hash_table table;
	load_table(table, BROJ_ELEMENATA, v);

	cout << "Dogodilo se konflikata: " << table.get_nr_conflicts() << endl;

	return 0;
}