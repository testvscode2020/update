#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "celestial_body.h"

using namespace std;

/*
Ispišite podatke o najhladnijem i najtoplijem planetu.
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
	while (getline(in, line)) {

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

bool sort_by_day_temp(celestial_body a, celestial_body b)
{
	return a.mean_temperature_c < b.mean_temperature_c;
}

void print(celestial_body &body)
{
	cout << "(temp=" << body.mean_temperature_c << ") " << body.name << ", " << body.type << ", godina traje: " << body.orbital_period_years << endl;
}

int main() {
	ifstream in("Solar System.csv");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<celestial_body> v;
	
	load(in, v);
	in.close();

	nth_element(v.begin(), v.begin(), v.end(), sort_by_day_temp);
	cout << "Najhladniji ";
	print(*v.begin());

	nth_element(v.begin(), v.end() - 1, v.end(), sort_by_day_temp);
	cout << "Najtopliji ";
	print(*(v.end() - 1));


	return 0;
}