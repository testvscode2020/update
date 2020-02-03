#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "hash_table.h"

using namespace std;

/*
Promijenite prethodni zadatak tako da konflikte razrješavate
ulančavanjem. Ispišite u posebnu datoteku stanje hash tablice
(redni broj bucketa te broj ključeva koji se nalaze u njemu).
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

void write(ofstream &out, hash_table &table)
{
	for (int i = 0; i < table.get_buckets(); i++) 
	{
		out 
			<< "Bucket " << i << ": " 
			<< table.get_elements_in_bucket(i) << " elements" 
			<< endl;
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

	ofstream out("buckets.txt");
	if (!out) {
		cout << "Greska pri otvaranju datoteke za pisanje" << endl;
		return -1;
	}
	write(out, table);
	out.close();

	return 0;
}