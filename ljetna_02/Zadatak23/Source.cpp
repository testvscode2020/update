#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

/*
U prilogu su tri C++ datoteke, dvije neispravne i jedna ispravna. 
Napišite program koji će provjeravati je li zadana C++ datoteka 
balansirana po pitanju zagrada ‘{‘, ‘[‘ i ‘(‘. Algoritam provjere
je sljedeći:
a) Prođite datoteku znak po znak.
b) Ako je znak otvarajuća zagrada, gurnite ga na stog.
c) Ako je znak zatvarajuća zagrada, skinite znak sa stoga
i usporedite jesu li jednaki. Ako nisu, greška i kraj.
d) Ako na kraju ostane išta na stogu, greška i kraj.
Iskoristite gornji algoritam i za svaku od tri datoteke iz 
priloga ispišite je li balansirana ili nije.
*/


bool check(ifstream &in, stack<char> &s)
{
	string line;
	while (getline(in, line))
	{
		for (unsigned i = 0; i < line.length(); i++)
		{
			if (line[i] == '{' || line[i] == '[' || line[i] == '(')
			{
				s.push(line[i]);
			}
			else if (line[i] == '}')
			{
				if (s.empty() || s.top() != '{')
				{
					return false;
				}
				s.pop();
			}
			else if (line[i] == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					return false;
				}
				s.pop();
			}
			else if (line[i] == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					return false;
				}
				s.pop();
			}
		}
	}
	return s.empty();
}

int main()
{
	ifstream in("proba1.txt");
	//ifstream in("proba2.txt");
	//ifstream in("proba3.txt");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}
	stack<char> s;

	if (check(in, s)) {
		cout << "Datoteka je ispravno balansirana" << endl;
	}
	else
	{
		cout << "Datoteka ima viska i nije balansirana" << endl;
	}
	in.close();
	return 0;
}