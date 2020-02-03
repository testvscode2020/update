#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Water_level.h"
using namespace std;
/*
	 Uzevši u obzir datoteku LakeHuron.csv, ispišite odgovor na sljedeće pitanje: koje godine je vodostaj rijeke Huron (Michigan) bio najviši. 
	 Rješenje mora raditi i prilikom izmjene podataka o godinama i vodostajima u datoteci (tj. Ne možete samo ispisati „1872“ :)). 
*/
template <typename T>
T convert(string& s)
{
	T result;
	stringstream converter(s);
	converter >> result;
	return result;
}

void ParseFile(ifstream &file, vector<Water_level> &levels)
{
	string temp_line;

	getline(file, temp_line); 

	while (getline(file, temp_line))
	{
		stringstream ss(temp_line);
		string temp;

		getline(ss, temp, ',');

		getline(ss, temp, ',');
		int year = convert<int>(temp);
		
		getline(ss, temp, ',');
		
		double level = convert<double>(temp);
		
		Water_level water_level(year, level);

		levels.push_back(water_level);
	}
}

Water_level find_highest(vector<Water_level>& levels)
{
	Water_level highest = levels[0];

	for (int i = 0; i < levels.size(); i++)
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
	ifstream file("LakeHuron.csv");
	
	if (!file)
	{
		cout << "Nema file-a" << endl;

		return 1;
	}

	vector<Water_level> levels;
	
	ParseFile(file, levels);

	file.close();

	Water_level highest = find_highest(levels);

	cout << "Highest is: " << highest.to_string() << endl;

	return 0;
}