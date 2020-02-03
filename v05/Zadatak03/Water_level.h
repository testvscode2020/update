#pragma once
#include <string>
class Water_level
{
public:
	Water_level(const int year, const double level);
	std::string to_string() const;
	int get_year() const;
private:
	int year;
	double level;
};

