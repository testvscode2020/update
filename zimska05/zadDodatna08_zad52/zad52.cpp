/*
 Datoteka popular_baby_names_usa.zip sadrži podatke o broju 
 roðene djece odreðenog imena u SAD od 1880. do 2017. Koristeæi 
 prikladnu hash tablicu, ispišite u novu datoteku koliko je kojeg 
 imena ukupno bilo u 1981 (vodite raèuna da neko ime može biti i muško i žensko).
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map> //radi preko hash.tablici, map radi preko binary tree! vazno!
using namespace std;

int convert(string& s)
{
	stringstream ss(s);
	int i;
	ss >> i;
	return i;
}


void load(ifstream& in, unordered_map<string, int>& m)
{
	string line;
	while (getline(in,line))
	{
		//cout << line << endl;
		stringstream ss(line);
		string name;
		getline(ss, name, ',');
		if (name[0] !='A') //string je array charaktera, zato se to moze!!
		{
			continue; //nastavi dalje sa loopom
		}
		string gender;
		getline(ss, gender, ',');

		string broj_s;
		getline(ss, broj_s);

		//cout << "hi mom!";
		int broj = convert(broj_s);

		//m[name] = m[name] + broj;
		m[name+"_"+gender] += broj; //naknadno smo dodali +"_"+gender
	}
}

void save(ofstream& out, unordered_map<string, int> &m)
{
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		out << it->first << ": " << (*it).second << endl; // jedno i drugo je isto. 
	}

}


int main() 
{
	ifstream in("yob1999.txt");
	ofstream out("imena_na_a.txt");
	if (!in || !out)
	{
		cout << "404" << endl;
		return 1;
	}
	
	unordered_map<string, int> m;
	load(in, m);
	save(out, m);

	in.close();
	out.close();

	return 0;
}
