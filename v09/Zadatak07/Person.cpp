#include "Person.h"
#include <sstream>

Person::Person(std::string gender, int weight, int height)
{
	this->gender = gender;
	this->weight = weight;
	this->height = height;
}

std::string Person::to_string() const
{
	std::stringstream ss;
	ss << "ibm: " << ibm() << ", gender: " << gender << ", weight: " << weight << ", height: " << height;
	return ss.str();
}

double Person::ibm() const
{
	return weight / pow(height/100.0, 2);
}
