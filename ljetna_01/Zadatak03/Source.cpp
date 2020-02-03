#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Water_Level.h"


/*
Uzevši u obzir datoteku LakeHuron.csv, ispišite
odgovor na sljedeće pitanje: koje godine je vodostaj
rijeke Huron (Michigan) bio najviši. Rješenje mora
raditi i prilikom izmjene podataka o godinama i
vodostajima u datoteci (tj. Ne možete samo ispisati „1872“)
*/

using namespace std;

template <typename T>
T convert(string &s)
{
	T result;
	stringstream converter(s);
	converter >> result;
	return result;
}

void load(ifstream &in, vector<Water_Level> &levels)
{
	string line;
	//skip header
	getline(in, line);
	while (getline(in, line))
	{
		stringstream ss(line);
		string temp;
		//skip column
		getline(ss, temp, ',');
		//get year
		getline(ss, temp, ',');
		int year = convert<int>(temp);
		//get level
		getline(ss, temp, ',');
		double level = convert<double>(temp);
		levels.emplace_back(year, level);
	}
}

void print(Water_Level &level)
{
	cout << level.to_string() << endl;
}

Water_Level find_highest(vector<Water_Level> &levels)
{
	Water_Level highest = levels[0];
	for (unsigned i = 1; i < levels.size(); i++)
	{
		if (levels[i].get_level() > highest.get_level())
		{
			highest = levels[i];
		}
	}
	return highest;
}


int main()
{
	ifstream in("LakeHuron.csv");
	if (!in)
	{
		cout << "File does not exist!" << endl;
		return 1;
	}

	vector<Water_Level> levels;
	load(in, levels);

	in.close();

	//test printing
	for_each(levels.begin(), levels.end(), print);

	Water_Level highest = find_highest(levels);
	cout << "Highest level: " << highest.to_string() << endl;

	return 0;
}