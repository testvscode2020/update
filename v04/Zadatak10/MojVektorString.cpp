#include "MojVektorString.h"

MojVektorString::MojVektorString(unsigned n, std::string val) {
	values = new std::string[n];
	for (unsigned i = 0; i < n; i++) {
		values[i] = val;
	}
	next = n;
	cap = n;
}

MojVektorString::~MojVektorString() {
	if (values != nullptr) {
		delete[] values;
	}
}

void MojVektorString::push_back(std::string val) {
	if (next == cap) {
		grow();
	}
	values[next++] = val;
}

unsigned MojVektorString::size() {
	return next;
}

unsigned MojVektorString::capacity() {
	return cap;
}

std::string MojVektorString::at(unsigned i) {
	return values[i];
}

void MojVektorString::grow() {
	// Novi kapacitet.
	cap += 5;
	//Novi prostor
	std::string *new_values = new std::string[cap];
	//Kopiranje
	for (unsigned i = 0; i < next; i++) {
		new_values[i] = values[i];
	}
	//otpustanje
	delete[] values;
	//kopiranje adrese
	values = new_values;
}
