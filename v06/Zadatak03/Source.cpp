#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
Kreirajte red stringova. Potom:
•Učitajte od korisnika tri imena i dodajte ih u red.
•Ispišite sav sadržaj reda.
*/

int main() 
{
	queue<string> q;
	for (unsigned i = 0; i < 3; i++) 
	{
		cout << "Upisite " << i + 1 << " ime: ";
		string temp;
		getline(cin, temp);
		q.push(temp);
	}

	while (!q.empty()) 
	{
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}