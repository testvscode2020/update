#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

/*
Ubacite sve podatke iz Sifre_drzava.csv u najprikladniji 
kontejner za brzo pretraživanje po šifri države. 
Omogućite korisniku da unosi šifru države, a vi mu onda 
ispišite puni naziv države.
*/

void load(ifstream &in, map<string, string> &m)
{
	string line;
	getline(in, line);
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		string name;
		getline(ss, name, ';');
		string code;
		ss >> code;
		//m.insert(pair<string, string>(code, name));
		m[code] = name;
	}
}

void search(map<string, string> &m)
{
	bool dalje;
	int broj;
	do
	{
		cout << "Unesite sifru drzave:";
		string code;
		cin >> code;

		map<string, string>::iterator found = m.find(code);
		if (found != m.end()) {
			cout << found->second << endl;
		}
		else
		{
			cout << "Nema drzave s tom sifrom" << endl;
		}

		cout << "Dalje (1=da, 0=ne)? ";
		cin >> dalje;
	} while (dalje);
}

int main() 
{
	ifstream in("Sifre_drzava.csv");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	map<string, string> m;
	load(in, m);
	in.close();

	search(m);

	return 0;
}