#include <iostream>
#include <list>
#include <stack>

using namespace std;

/*
Kreirajte listu od 10 brojeva pa od nje napravite stog. 
Ispišite sadržaj stoga.
*/

int main() 
{
	list<int> l = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	stack<int, list<int>> s(l);

	while (!s.empty()) 
	{
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}