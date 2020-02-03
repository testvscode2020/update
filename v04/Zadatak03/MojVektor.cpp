#include "MojVektor.h"

MojVektor::MojVektor(unsigned n, std::string value) {
	for (unsigned i = 0; i < n; i++) {
		values[i] = value;
	}
	s = n;
}

unsigned MojVektor::size() {
	return s;
}

std::string MojVektor::at(unsigned i) {
	return values[i];
}
