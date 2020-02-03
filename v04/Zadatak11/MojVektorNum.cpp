#include "MojVektorNum.h"
using namespace std;

MojVektorNum::iterator::iterator(int* ptr) {
	this->ptr = ptr;
}

int& MojVektorNum::iterator::operator*() {
	return *ptr;
}

MojVektorNum::iterator& MojVektorNum::iterator::operator++() {
	ptr++;
	return *this;
}

bool MojVektorNum::iterator::operator==(const MojVektorNum::iterator& rhs) {
	return ptr == rhs.ptr;
}

bool MojVektorNum::iterator::operator!=(const MojVektorNum::iterator& rhs) {
	return ptr != rhs.ptr;
}

void MojVektorNum::push_back(int val) {
	values[next++] = val;
}

MojVektorNum::iterator MojVektorNum::begin() {
	return values;
}

MojVektorNum::iterator MojVektorNum::end() {
	return (values + next);
}