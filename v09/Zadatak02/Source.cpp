#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

/*
Napravite vektor od 10 slučajnih brojeva između 1 i 100 i onda:
a. Ispišite sve brojeve.
b. Napravite prioritetni red i u njega ubacite sve brojeve iz vektora.
c. Učitavajte od korisnika brojeve dok on to želi i dodajte ih u prioritetni red.
d. Ispišite sve brojeve iz prioritetnog reda.
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

void insert(priority_queue<int> &pq)
{
	bool dalje;
	int n;
	do
	{
		cout << "Unesite broj: ";
		cin >> n;
		pq.push(n);
		cout << "Dalje (1=da, 0=ne): ";
		cin >> dalje;
	} while (dalje);
}

int main() 
{
	vector<int> numbers = fill_numbers(10, 1, 100);

	cout << "vektor: ";
	print(numbers);

	priority_queue<int> pq(numbers.begin(), numbers.end());

	insert(pq);

	cout << "prioritetni red: ";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}