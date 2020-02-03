#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

/*
Uzmite sve brojeve od 1 do milijun, promiješajte ih i smjestite u set i 
unordered_set. Ispišite koliko je trajalo umetanje u svaki kontejner. 
Nakon toga pitajte korisnika koji broj traži pa ispišite trajanje traženja u 
svakom od kontejnera.
*/

void prepare_vector(vector<int> &v, const int N) 
{
	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

template<typename T>
void measure_insert(vector<int> &v, T &t) 
{
	auto begin = high_resolution_clock::now();
	for (int n : v)
	{
		t.insert(n);
	}
	auto end = high_resolution_clock::now();
	cout
		<< "Vrijeme: "
		<< duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}

template<typename T>
void measure_search(T &t, int query)
{
	auto begin = high_resolution_clock::now();
	auto it = t.find(query);
	auto end = high_resolution_clock::now();
	
	if (it != t.end())
	{
		cout << "res: " << *it << endl;
	}
	cout
		<< "Vrijeme: "
		<< duration_cast<chrono::microseconds>(end - begin).count()
		<< " us" << endl;
}

int main()
{
	srand(time(nullptr));
	const int N = 1000000;
	vector<int> v;
	prepare_vector(v, N);

	set<int> set;
	cout << "Umetanje u set:" << endl;
	measure_insert(v, set);

	unordered_set<int> uset;
	cout << "Umetanje u unordered set:" << endl;
	measure_insert(v, uset);

	int query;
	cout << "Koji broj zelite pronaci: ";
	cin >> query;

	cout << "Pretraga u setu:" << endl;
	measure_search(set, query);

	cout << "Pretraga u unordered setu:" << endl;
	measure_search(uset, query);

	return 0;
}