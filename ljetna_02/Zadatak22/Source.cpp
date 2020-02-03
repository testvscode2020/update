#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/*
U prilogu se nalazi ulazna datoteka „brojevi.txt“ koja sadrži točno 25 brojeva međusobno odvojenih jednim razmakom, dok se iza zadnjeg broja nalazi znak enter. Vaši su zadaci sljedeći:
-Učitajte sve brojeve u listu (koristite list<T>).
-Iz liste izbrišite sve negativne brojeve.
-Preostale brojeve pomnožite sa 3.
-Sve brojeve iz liste prepišite od kraja prema početku u vektor.
-Sve brojeve u vektoru pomnožite sa 3.
-Sve brojeve iz vektora smjestite na stog.
-Ispišite sve elemente stoga.
*/


void load(ifstream &in, list<int> &l)
{
	int n;
	while (in >> n)
	{
		l.push_back(n);
	}
}

void print(int &n)
{
	cout << n << " ";
}

void remove_negative(list<int> &l)
{
	for (auto it = l.begin(); it != l.end(); )
	{
		if (*it < 0)
		{
			it = l.erase(it);
		}
		else 
		{
			++it;
		}
	}
}

bool is_negative(int &n)
{
	return n < 0;
}

void multiply(int &n)
{
	n *= 3;
}

void fill_stack(vector<int> &v, stack<int> &s)
{
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		s.push(*it);
	}
}

int main()
{
	ifstream in("brojevi.txt");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	list<int> l;
	//Ucitajte sve brojeve u listu (koristite list<T>)
	load(in, l);
	in.close();

	//provjera
	cout << "Ucitani brojevi: ";
	for_each(l.begin(), l.end(), print);
	cout << endl;

	//Iz liste izbrisite sve negativne brojeve
	//rucno:
	//remove_negative(l);
	//drugi nacin:
	l.remove_if(is_negative);
	//provjera
	cout << "Bez negativnih: ";
	for_each(l.begin(), l.end(), print);
	cout << endl;

	//Preostale brojeve pomnozite sa 3
	for_each(l.begin(), l.end(), multiply);
	cout << "Pomnozeni s 3: ";
	for_each(l.begin(), l.end(), print);
	cout << endl;

	//Sve brojeve iz liste prepisite od kraja prema pocetku u vektor
	vector<int> v(l.rbegin(), l.rend());
	//fill_vector(l, v);
	cout << "Obrnuti u vektoru: ";
	for_each(v.begin(), v.end(), print);
	cout << endl;

	//Sve brojeve u vektoru pomnozite sa 3
	for_each(v.begin(), v.end(), multiply);
	cout << "Pomnozeni s 3: ";
	for_each(v.begin(), v.end(), print);
	cout << endl;

	//Sve brojeve iz vektora smjestite na stog
	stack<int> s;
	fill_stack(v, s);
	//Ispisite sve elemente stoga
	cout << "Brojevi na stogu: ";
	while (!s.empty())
	{
		print(s.top());
		s.pop();
	}
	cout << endl;

	return 0;
}