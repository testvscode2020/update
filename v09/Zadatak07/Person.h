#pragma once
#include <string>

class Person
{
private:
	std::string gender;
	int weight;
	int height;
public:
	Person(std::string gender, int weight, int height);
	std::string to_string() const;
	double ibm() const;
};

struct person_ibmcomparer_desc
{
	bool operator() (const Person &p1, const Person &p2) const
	{
		return p1.ibm() < p2.ibm();
	}
};

