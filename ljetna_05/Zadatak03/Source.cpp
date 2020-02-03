#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

/*
U datoteci Racuni.csv se nalazi popis svih izdanih računa. 
Omogućite korisniku da upiše ID kupca, a vi ispišite brojeve svih 
računa izdanih tom kupcu. Koju kolekciju će te upotrijebiti i zašto?
*/

void load(ifstream &in, multimap<int, string> &mm)
{
	string line;
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		int id;
		string racun;
		ss >> id >> racun;
		mm.insert(pair<int, string>(id, racun));
	}
}

void search(multimap<int, string> &mm, int &id)
{
	//pair<map<int, string>::iterator, map<int, string>::iterator> found = mm.equal_range(id);
	auto found = mm.equal_range(id);
	if (found.first != found.second)
	{
		for (auto it = found.first; it != found.second; it++)
		{
			cout << it->second << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "kupac ne postoji" << endl;
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
	multimap<int, string> mm;
	load(in, mm);
	in.close();

	bool dalje;
	do
	{
		int id;
		cout << "id:";
		cin >> id;
		search(mm, id);

		cout << "Dalje(0/1)?";
		cin >> dalje;
		cin.ignore();
	} while (dalje);

	return 0;
}