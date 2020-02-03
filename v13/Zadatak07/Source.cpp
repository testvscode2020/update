#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;


/*
Datoteka popular_baby_names_usa.zip sadrži podatke o broju rođene 
djece određenog imena u SAD od 1880. do 2017. Koristeći prikladnu hash
tablicu, ispišite sva imena iz 1901. kojih nije više bilo 2001.
*/

void load(ifstream &in, unordered_set<string> &s)
{
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		string key;
		getline(ss, key, ',');
		s.insert(key);
	}
}

void print_nonexistent(ifstream &in, unordered_set<string> &s)
{
	int n = 1;
	string line;
	while (getline(in, line))
	{
		stringstream ss(line);
		string key;
		getline(ss, key, ',');
		if (s.find(key) == s.end())
		{
			cout << n++ << ": " << key << endl;
		}
	}
}

int main()
{
	ifstream in1("yob2001.txt");
	ifstream in2("yob1901.txt");
	if (!in1 || !in2)
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
	}

	unordered_set<string> s;
	load(in1, s);
	in1.close();
	print_nonexistent(in2, s);
	in2.close();

	return 0;
}