#include "hash_table.h"

int hash_table::h(int key) 
{
	return key;
}

hash_table::hash_table(unsigned n) 
{
	array = new unsigned long long[n];
}

void hash_table::insert(int key, unsigned long long value) 
{
	array[h(key)] = value;
}

unsigned long long hash_table::search(int key) 
{
	return array[h(key)];
}

hash_table::~hash_table() 
{
	delete[] array;
}
