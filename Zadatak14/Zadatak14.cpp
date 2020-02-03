#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void load(ifstream& input, unordered_map<string, int>& map)
{
	string line;
	while (getline(input, line))
	{
		stringstream ss(line);
		string key;
		getline(ss, key, ',');

		string gender;
		getline(ss, gender, ',');
		key += "_" + gender;

		string temp;
		getline(ss, temp);
		int value;

		stringstream tempss(temp);
		tempss >> value;

		map[key] += value;
	}
}

void print(ofstream& output, unordered_map<string, int>& map)
{
	for (auto i = map.begin(); i != map.end(); i++)
	{
		output << i->first << ": " << i->second << endl;
	}
}

int main()
{
	ifstream input("yob1981.txt");
	ofstream output("yobSuma.txt");
	unordered_map<string, int> map;
	load(input, map);
	input.close();

	print(output, map);
	output.close();

	return 0;
}