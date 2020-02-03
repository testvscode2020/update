#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>

using namespace std;

/*
U datoteci Racuni.csv se nalazi popis svih izdanih 
računa za pojedine kupce (identifikator ID). 
Odabrite kolekciju za čuvanje identifikatora kupaca, 
spremite sve identifikatore i ispišite ih. Kako su poredani
identifikatori i zašto?
Promijenite implementaciju zadatka na način da omogućite 
korisniku da upiše broja računa, a vi ispišite identifikator
kupca kojem je izdan taj račun.
*/

void load(ifstream &in, set<int> &s, map<string, int> &m)
{
	string line;
	while (getline(in,line))
	{
		//cout << line << endl;
		stringstream ss(line);
		int id;
		string racun;
		ss >> id >> racun;
		s.insert(id);
		//m.insert(pair<string, int>(racun, id));
		m[racun] = id;
	}
}

void print(set<int> &s)
{
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;
	}
}

void search(map<string, int> &m, string &racun)
{
	//map<string, int>::iterator found = m.find(racun);
	auto found = m.find(racun);
	if (found != m.end())
	{
		cout << found->first << " je izdan kupcu: " << found->second << endl;
	}
	else 
	{
		cout << "racun ne postoji" << endl;
	}
}

int main()
{
	ifstream in("Racuni.csv");
	if (!in)
	{
		cout << "nije moguce pristupiti" << endl;
		return 1;
	}
	set<int	> s;
	map<string, int> m;
	load(in, s, m);
	in.close();

	//print(s);

	bool dalje;
	do
	{
		string racun;
		cout << "racun:";
		getline(cin, racun);
		search(m, racun);

		cout << "Dalje(0/1)?";
		cin >> dalje;
		cin.ignore();
	} while (dalje);

	return 0;
}