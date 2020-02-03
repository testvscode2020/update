#pragma once
#include <string>
using namespace std;

class Water_Level
{
public:
	Water_Level(int year, double level);
	string to_string();
	double get_level();
private:
	int year;
	double level;
};

