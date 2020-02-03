#pragma once
#include <string>
using namespace std;

struct celestial_body 
{
	string name;
	string type;
	double mean_distance_from_sun_au;
	double orbital_period_years;
	double rotation_period_days;
	double mean_temperature_c;
};