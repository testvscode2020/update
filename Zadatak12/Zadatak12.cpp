#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void load(ifstream& input, vector<string>& osobe)
{
	string name;

	while (getline(input, name))
	{
		osobe.push_back(name);
	}
}

void print(vector<string>& v)
{
	for (string s : v)
	{
		cout << s << endl;
	}
}

bool sort_by_length(string first, string second)
{
	return first.length() > second.length();
}

int main()
{
	ifstream input("osobe.txt");
	vector<string> osobe;

	load(input, osobe);
	input.close();

	sort(osobe.begin(), osobe.end());

	stable_sort(osobe.begin(), osobe.end(), sort_by_length);

	print(osobe);

	return 0;
}