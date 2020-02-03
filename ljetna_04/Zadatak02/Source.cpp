#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/*
U prilogu je datoteka sa 10 izreka. Nakon učitavanja izreka
iz datoteke, učinite sljedeće:
• učitajte rečenice u vektor
• prepišite rečenice iz vektora u listu u obrnutom redoslijedu
• iz liste izbrišite rečenice koje počinju sa slovom L
• svim rečenicama izmijenite prvo slovo tako da bude slovo M
• smjestite rečenice na stog
• prepišite rečenice sa stoga u red
• ispišite rečenice iz reda
*/

void load(ifstream &in, vector<string> &v)
{
	string line;
	while (getline(in, line))
	{
		v.push_back(line);
	}
}

void print(string &line)
{
	cout << line << endl;
}

bool starts_with_L(string &line)
{
	return line[0] == 'L';
}

void change_first_letter_to_M(string &line)
{
	line[0] = 'M';
}

void fill_stack(list<string> &l, stack<string> &s)
{
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		s.push(*it);
	}
}

int main()
{
	ifstream in("izreke.txt");
	if (!in)
	{
		cout << "Nije moguce pristupiti" << endl;
		return 1;
	}

	vector<string> v;
	load(in, v);
	in.close();

	cout << "izreke u vektoru:" << endl;
	for_each(v.begin(), v.end(), print);
	cout << endl;

	list<string> l(v.rbegin(), v.rend());
	cout << "obrnute izreke u listi:" << endl;
	for_each(l.begin(), l.end(), print);
	cout << endl;

	l.remove_if(starts_with_L);
	cout << "lista bez L:" << endl;
	for_each(l.begin(), l.end(), print);
	cout << endl;

	for_each(l.begin(), l.end(), change_first_letter_to_M);
	cout << "izreke s M:" << endl;
	for_each(l.begin(), l.end(), print);
	cout << endl;

	stack<string> s;
	fill_stack(l, s);
	
	queue<string> q;
	cout << "stack: " << endl;
	while (!s.empty())
	{
		q.push(s.top());
		print(s.top());
		s.pop();
	}
	cout << endl;

	cout << "queue: " << endl;
	while (!q.empty())
	{
		print(q.front());
		q.pop();
	}
	cout << endl;


	return 0;
}