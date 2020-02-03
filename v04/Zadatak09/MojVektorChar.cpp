#include "MojVektorChar.h"

void MojVektorChar::push_back(char val) {
	values[next++] = val;
}

unsigned MojVektorChar::size() {
	return next;
}

char MojVektorChar::at(unsigned i) {
	return values[i];
}
