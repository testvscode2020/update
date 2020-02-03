#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
Kreirajte stog cijelih brojeva s vektorom kao adaptiranim kontejnerom. Potom:
•Dodajte brojeve od 1 do 5 u stog.
•Ispišite sav sadržaj stoga.
*/

int main() 
{	
	stack<int, vector<int>> s;
	for (unsigned i = 1; i <= 5; i++) 
	{
		s.push(i);
	}

	while (!s.empty()) 
	{
		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}