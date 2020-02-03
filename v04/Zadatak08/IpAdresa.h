#pragma once
#include <string>

class IpAdresa {
private:
	int a, b, c, d;

public:
	IpAdresa(int a, int b, int c, int d);
	std::string to_string();
	char which_class();
};

