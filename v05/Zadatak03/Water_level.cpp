#include "Water_level.h"
#include <sstream>

Water_level::Water_level(const int year, const double level) {
	this->year = year;
	this->level = level;
}

std::string Water_level::to_string() const {
	std::stringstream ss;
	ss << year << " : " << level;
	return ss.str();
}

int Water_level::get_year() const {
	return year;
}