#include "direct_addressing_table.h"

direct_addressing_table::direct_addressing_table(unsigned n) 
{
	array = new unsigned long long[n];
}

void direct_addressing_table::insert(int key, unsigned long long value) 
{
	array[key] = value;
}

unsigned long long direct_addressing_table::search(int key) 
{
	return array[key];
}

direct_addressing_table::~direct_addressing_table() 
{
	delete[] array;
}
