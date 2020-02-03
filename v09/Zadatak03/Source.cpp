#include <iostream>
#include <ctime>
#include <queue>
#include <functional>

using namespace std;

/*
Kreirajte prioritetni red od 10 slučajnih brojeva između 1 i 100 i
potom ispišite brojeve. Brojevi se moraju ispisivati od manjih
prema većim (min-heap). Koristite ugrađenu implementaciju
komparatora.
*/

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

priority_queue<int, vector<int>, greater<int>> fill_numbers(unsigned n, int min, int max)
{
	srand(time(nullptr));
	priority_queue<int, vector<int>, greater<int>> pq;
	for (unsigned i = 0; i < n; i++)
	{
		pq.push(generate_random(min, max));
	}
	return pq;
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq = fill_numbers(10, 1, 100);
	cout << "prioritetni red:";
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}