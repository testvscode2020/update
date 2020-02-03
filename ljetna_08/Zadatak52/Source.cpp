#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
Datoteka popular_baby_names_usa.zip sadrži podatke o 
broju rođene djece određenog imena u SAD od 1880. do 2017. 
Koristeći prikladnu hash tablicu, ispišite u novu datoteku
koliko je kojeg imena ukupno bilo u 1981 (vodite računa da neko 
ime može biti i muško i žensko).
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
		//cout << line << endl;
		stringstream ss(line);
		string key;
		getline(ss, key, ',');

		string temp;
		getline(ss, temp, ',');
		//example
		//Aaren: 14
		//comment code to see the difference:
		key += "_" + temp;
		//Aaren_F: 8
		//Aaren_M: 6

		getline(ss, temp);
		int value = convert<int>(temp);
		m[key] += value;
	}
}

void write(ofstream &out, unordered_map<string, int> &m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << ": " << it->second << endl;
	}
}



int main()
{
	ifstream in("yob1981.txt");
	ofstream out("yobSuma.txt");
	if (!in || !out)
	{
		cout << "Nije moguce pristupiti datotekama" << endl;
	}

	unordered_map<string, int> m;
	load(in, m);
	in.close();

	write(out, m);
	out.close();

	return 0;
}