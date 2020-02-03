#include <iostream>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

int randomNumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void generateNumbers(int min, int max, int numberOfNumbers, vector<int> &v)
{
	for (int i = 0; i < numberOfNumbers; i++)
	{
		v.push_back(randomNumber(min, max));
	}
}

void print_ascending(vector<int> &v)
{
	priority_queue<int, vector<int>, greater<int>> priorityQueue(v.begin(), v.end());
	while (!priorityQueue.empty())
	{
		cout << priorityQueue.top() << " ";
		priorityQueue.pop();
	}

	cout << endl;
}

void print_descending(vector<int>& v)
{
	priority_queue<int, vector<int>> priorityQueue(v.begin(), v.end());
	while (!priorityQueue.empty())
	{
		cout << priorityQueue.top() << " ";
		priorityQueue.pop();
	}

	cout << endl;
}

int main()
{
	srand(time(nullptr));
	vector<int> v;

	generateNumbers(1, 100, 10  , v);

	int order;
	cout << "Order (1-asc, 2-desc):";
	cin >> order;

	switch (order)
	{
	case 1:
		print_ascending(v);
		break;
	case 2:
		print_descending(v);
		break;
	}

	return 0;
}