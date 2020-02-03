#pragma once
#include <string>
class MojVektorString
{
public:
	MojVektorString(unsigned n, std::string val);
	~MojVektorString();
	void push_back(std::string val);
	unsigned size();
	unsigned capacity();
	std::string at(unsigned i);
private:
	std::string* values = nullptr;
	unsigned next = 0;
	unsigned cap = 0;
	void grow();
};

