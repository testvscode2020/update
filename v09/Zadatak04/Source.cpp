#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

/*
Riješite prethodni zadatak korištenjem vlastitog komparatora.
*/

struct int_comparer_asc
{
	bool operator()(const int &i1, const int &i2) const
	{
		return i1 > i2;
	}
};

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

priority_queue<int, vector<int>, int_comparer_asc> fill_numbers(unsigned n, int min, int max)
{
	srand(time(nullptr));
	priority_queue<int, vector<int>, int_comparer_asc> pq;
	for (unsigned i = 0; i < n; i++)
	{
		pq.push(generate_random(min, max));
	}
	return pq;
}

int main()
{
	priority_queue<int, vector<int>, int_comparer_asc> pq = fill_numbers(10, 1, 100);

	cout << "prioritetni red:";;
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}