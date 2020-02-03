#include "hash_table.h"

int hash_table::h(int key) 
{
	return key % M;
}

hash_table::hash_table() 
{
	array = new unsigned long long[M] {0};
}

void hash_table::insert(int key, unsigned long long value) 
{
	int slot = h(key);
	if (array[slot] != 0) 
	{
		nr_conflicts++;
	}
	array[slot] = value;
}

unsigned long long hash_table::search(int key) 
{
	return array[h(key)];
}

int hash_table::get_nr_conflicts() 
{
	return nr_conflicts;
}

hash_table::~hash_table() 
{
	delete[] array;
}