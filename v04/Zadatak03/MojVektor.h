#pragma once
#include <string>

class MojVektor {
private:
	std::string values[50];
	unsigned s;
public:
	MojVektor(unsigned n, std::string value);
	//alias za unsigned int
	unsigned size();
	std::string at(unsigned i);
};

