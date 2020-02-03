#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
Datoteka popular_baby_names_usa.zip sadrži podatke o broju rođene djece 
određenog imena u SAD od 1880. do 2017. Koristeći prikladnu hash tablicu, 
ispišite u novu datoteku koliko je kojeg imena ukupno bilo u 1901. i 2001. 
Primjer ispisa:
Mary, 18936
*/

template<typename T>
T convert(string &s)
{
	stringstream c(s);
	T t;
	c >> t;
	return t;
}

void load(ifstream &in, unordered_map<string, int> &m)
{
	string line;
	while (getline(in, line)) 
	{
		stringstream ss(line);
		string key;
		getline(ss, key, ',');

		string temp;
		getline(ss, temp, ',');

		getline(ss, temp);
		int value = convert<int>(temp);
		m[key] += value;
	}
}

void write(ofstream &out, unordered_map<string, int> &m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << ", " << it->second << endl;
	}
}


int main()
{
	ifstream in1("yob1901.txt");
	ifstream in2("yob2001.txt");
	ofstream out("yobSuma.txt");
	if (!in1 || !in2 || !out) 
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
	}

	unordered_map<string, int> m;
	load(in1, m);
	load(in2, m);
	in1.close();
	in2.close();

	write(out, m);
	out.close();

	return 0;
}