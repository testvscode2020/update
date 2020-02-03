#include "Water_Level.h"
#include <sstream>

Water_Level::Water_Level(int year, double level)
{
	this->level = level;
	this->year = year;
}

string Water_Level::to_string()
{
	stringstream ss;
	ss << year << " : " << level;
	return ss.str();
}

double Water_Level::get_level()
{
	return level;
}
