#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#include "Water_level.h"

using namespace std;

/*
Učitajte vodostaje rijeke Huron u listu. Potom zatražite
korisnika da unese godinu i uzlazno (prema godini) ispišite
vodostaje do zatražene godine, uključujući i nju samu. Potom
zatražite korisnika da unese godinu i izbrišite vodostaje do
zatražene godine, uključujući i nju samu. Ispišite konačnu listu
vodostaja silazno prema godini.
*/


template<typename T>
T convert(string &s) {
	T result;
	stringstream converter(s);
	converter >> result;
	return result;
}

void load_data(ifstream &in, list<Water_level> &levels) {
	string line;
	//skip header
	getline(in, line);
	string temp;
	while (getline(in, line)) {
		//cout << line << endl;
		stringstream ss(line);
		//skip
		getline(ss, temp, ',');
		//year		
		getline(ss, temp, ',');
		int year = convert<int>(temp);
		//level		
		getline(ss, temp);
		double level = convert<double>(temp);
		levels.emplace_back(year, level);
	}
}

void print(Water_level &level) {
	cout << level.to_string() << endl;
}

int main() {
	ifstream in("LakeHuron.csv");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
	}
	list<Water_level> levels;
	load_data(in, levels);
	in.close();

	//provjera da li je uspio load
	//for_each(levels.begin(), levels.end(), print);

	cout << "Unesite godinu do koje zelite ispis rezultata: ";
	int year;
	cin >> year;
	for (auto it = levels.begin(); it != levels.end(); ++it) {
		if (it->get_year() <= year) {
			print(*it);
		}
	}

	//lambda expressions - za napredne (nije obavezno znati!)
	//[&] captures all variables used in the lambda by reference - tu trebamo year!
	//for_each(levels.begin(), levels.end(), [&](Water_level &wl) 
	//{
	//	if (wl.get_year() <= year) 
	//	{
	//		print(wl);
	//	}
	//});


	cout << "Unesite godinu do koje zelite izbrisati rezultate: ";
	cin >> year;

	for (auto it = levels.begin(); it != levels.end();) 
	{
		if (it->get_year() <= year) 
		{
			it = levels.erase(it);
		} else 
		{
			++it;
		}
	}

	//lambda expressions - za napredne (nije obavezno znati!)
	//levels.remove_if([&](Water_level &wl) 
	//{
	//	return wl.get_year() <= year; 
	//});

	for_each(levels.rbegin(), levels.rend(), print);

	return 0;
}