#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "celestial_body.h"

using namespace std;

/*
Ispišite podatke o tri planeta najdalja od sunca, na najefikasniji mogući način.
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

bool sort_by_distance_desc(celestial_body a, celestial_body b)
{
	return a.mean_distance_from_sun_au > b.mean_distance_from_sun_au;
}

void print(celestial_body &body)
{
	cout << "(d=" << body.mean_distance_from_sun_au << ") " << body.name << ", " << body.type << ", godina traje: " << body.orbital_period_years << endl;
}

int main() 
{
	ifstream in("Solar System.csv");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<celestial_body> v;
	load(in, v);
	in.close();

	const int nr_records = 3;

	partial_sort(v.begin(), v.begin() + nr_records, v.end(), sort_by_distance_desc);

	for_each(v.begin(), v.begin() + nr_records, print);

	return 0;
}