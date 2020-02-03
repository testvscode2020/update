#include <iostream>
#include <ctime>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/*
Kreirajte kontejner od 10 slučajnih brojeva između 
1 i 100. Pitajte korisnika da odabere smjer kojim 
želi ispisati brojeve (ASC ili DESC). Koristeći hrpu 
ili prioritetni red (prema želji), ispišite brojeve u 
zadanom smjeru.
*/

struct int_comparator_asc {
	bool operator() (const int &i1, const int &i2) const {
		return i1 > i2;
	}
};

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

vector<int> fill_numbers(unsigned n, int min, int max) {
	vector<int> v;
	for (unsigned i = 0; i < n; i++)
	{
		v.push_back(generate_random(min, max));
	}
	return v;
}

void print_asc_vector(vector <int> &v)
{
	cout << "vector asc: ";
	//make_heap(v.begin(), v.end(), greater<int>());
	make_heap(v.begin(), v.end(), int_comparator_asc());

	while (!v.empty())
	{
		cout << v.front() << " ";
		//pop_heap(v.begin(), v.end(), greater<int>());
		pop_heap(v.begin(), v.end(), int_comparator_asc());
		v.pop_back();
	}
	cout << endl;
}

void print_desc_vector(vector <int> &v)
{
	cout << "vector desc: ";
	make_heap(v.begin(), v.end());
	while (!v.empty())
	{
		cout << v.front() << " ";
		pop_heap(v.begin(), v.end());
		v.pop_back();
	}
	cout << endl;
}

void print_asc_queue(vector <int> &v)
{
	cout << "queue asc: ";
	//priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
	priority_queue<int, vector<int>, int_comparator_asc> pq(v.begin(), v.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void print_desc_queue(vector <int> &v)
{
	cout << "queue desc: ";
	priority_queue<int, vector<int>> pq(v.begin(), v.end());
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	srand(time(nullptr));
	vector<int> v = fill_numbers(10, 1, 100);
	int order;
	cout << "Order (1-asc, 2-desc):";
	cin >> order;

	switch (order)
	{
	case 1:
		//print_asc_vector(v);
		print_asc_queue(v);
		break;
	case 2:
		//print_desc_vector(v);
		print_desc_queue(v);
		break;
	}

	return 0;
}