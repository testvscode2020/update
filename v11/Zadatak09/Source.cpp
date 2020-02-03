#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>
#include "celestial_body.h"

using namespace std;

/*
Promijenite zadatak 4 tako da koristite listu. 
Usporedite trajanje ako ga rješavate vektorom u odnosu kad ga rješavate listom.
*/

template<typename T>
T convert(string &s)
{
	stringstream c(s);
	T t;
	c >> t;
	return t;
}

void load(ifstream &in, vector<celestial_body> &v)
{
	string line;
	getline(in, line);
	while (getline(in, line)) 
	{
		stringstream ss(line);
		string temp;
		getline(ss, temp, ','); // Skip Id

		celestial_body body;
		getline(ss, body.name, ',');
		getline(ss, body.type, ',');

		getline(ss, temp, ','); // Skip Order from Sun
		getline(ss, temp, ','); // Skip Diameter (Earth=1)
		getline(ss, temp, ','); // Skip Diameter (km)
		getline(ss, temp, ','); // Skip Mass (Earth=1)

		getline(ss, temp, ',');
		body.mean_distance_from_sun_au = convert<double>(temp);

		getline(ss, temp, ',');
		body.orbital_period_years = convert<double>(temp);

		getline(ss, temp, ','); // Skip Orbital Eccentricity
		getline(ss, temp, ','); // Skip Mean Orbital Velocity (km/sec)

		getline(ss, temp, ',');
		body.rotation_period_days = convert<double>(temp);

		getline(ss, temp, ','); // Skip Inclination of Axis (degrees)

		getline(ss, temp, ',');
		body.mean_temperature_c = convert<double>(temp);

		v.push_back(body);
	}
}

bool sort_by_distance(celestial_body a, celestial_body b)
{
	return a.mean_distance_from_sun_au < b.mean_distance_from_sun_au;
}

void print(celestial_body &body)
{
	cout << "(d=" << body.mean_distance_from_sun_au << ") " << body.name << ", " << body.type << ", godina traje: " << body.orbital_period_years << endl;
}

void measure_sort_vector(vector<celestial_body> &v)
{
	auto start = chrono::high_resolution_clock::now();
	sort(v.begin(), v.end(), sort_by_distance);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Vrijeme vektora: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " us" << endl;
}

void measure_sort_list(list<celestial_body> &l)
{
	auto start = chrono::high_resolution_clock::now();
	l.sort(sort_by_distance);
	auto end = chrono::high_resolution_clock::now();
	cout
		<< "Vrijeme liste: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " us" << endl;
}

int main() 
{
	ifstream in("Solar System.csv");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<celestial_body> original;
	load(in, original);
	in.close();

	vector<celestial_body> v(original);
	measure_sort_vector(v);
	for_each(v.begin(), v.end(), print);

	list<celestial_body> l(v.begin(), v.end());
	measure_sort_list(l);
	for_each(l.begin(), l.end(), print);

	return 0;
}