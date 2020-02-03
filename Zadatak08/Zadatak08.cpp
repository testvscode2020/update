#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

/*
	 Ubacite sve podatke iz Sifre_drzava.csv u najprikladniji kontejner za brzo pretra�ivanje po �ifri dr�ave.
	 Omogu�ite korisniku da unosi �ifru dr�ave, a vi mu onda ispi�ite puni naziv dr�ave
*/
void load_file(ifstream& input, map<string, string>& map)
{
	string line;
	getline(input, line);

	while (getline(input, line))
	{
		stringstream ss(line);
		
		string name;
		getline(ss, name, ';');
		
		string code;
		ss >> code;
		
		map.insert(pair<string, string>(code, name));
		//map[code] = name;
	}
}

void search(map<string, string>& m)
{
	bool dalje;
	
	do
	{
		cout << "Unesite sifru drzave: ";
		string code;
		cin >> code;

		map<string, string>::iterator found = m.find(code);
		if (found != m.end())
		{
			cout << found->second << endl;
		}
		else
		{
			cout << "Nema trazene drzave!" << endl;
		}


		cout << "Zelite li dalje (1 = da, 0 = ne)!" << endl;
		cin >> dalje;
	} while (dalje);
}

int main()
{	
	ifstream input("Sifre_drzava.csv");
	if (!input)
	{
		cout << "Nema fajla" << endl;
		return 1;
	}

	map<string, string> map;
	load_file(input, map);
	input.close();

	search(map);

	return 0;
}