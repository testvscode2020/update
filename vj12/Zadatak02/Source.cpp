#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>
#include "hash_table.h"

using namespace std;

/*
Uzmite sve brojeve od 1 do milijun, promiješajte ih i smjestite u
vlastitu implementaciju hash tablice uz hash funkciju h(key) = key.
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

void search(hash_table &table, int n)
{
	auto begin = chrono::high_resolution_clock::now();
	unsigned long long rez = table.search(n);
	auto end = chrono::high_resolution_clock::now();
	cout << rez << endl;
	cout
		<< "Vrijeme: "
		<< chrono::duration_cast<chrono::nanoseconds>(end - begin).count()
		<< " ns" << endl;
}


int main() 
{
	srand(unsigned(time(nullptr)));

	vector<int> v;
	const unsigned BROJ_ELEMENATA = 1000000;
	prepare_vector(v, BROJ_ELEMENATA);

	hash_table table(BROJ_ELEMENATA + 1);
	load_table(table, BROJ_ELEMENATA, v);

	int n;
	cout << "Upisite broj: ";
	cin >> n;
	search(table, n);

	return 0;
}