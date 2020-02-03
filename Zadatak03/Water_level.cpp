#include "Water_level.h"
#include <sstream>

Water_level::Water_level(int year, double level)
{
	this->year = year;
	this->level = level;
}

string Water_level::to_string()
{
	stringstream ss;

	ss << this->year << endl << this->level << endl;

	return ss.str();
}

double Water_level::get_level()
{
	return this->level;
}
