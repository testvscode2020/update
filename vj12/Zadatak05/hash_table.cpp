#include "hash_table.h"

int hash_table::h(int key)
{
	return key % M;
}

hash_table::hash_table()
{
	array = new list<entry>[M];
}

void hash_table::insert(int key, unsigned long long value)
{
	int slot = h(key);
	array[slot].push_back(entry(key, value));
}

unsigned long long hash_table::search(int key)
{
	int slot = h(key);
	for (auto it = array[slot].begin(); it != array[slot].end(); ++it)
	{
		if (it->key == key)
		{
			return it->value;
		}
	}
	return 0;
}

int hash_table::get_buckets()
{
	return M;
}

int hash_table::get_elements_in_bucket(int n)
{
	return array[n].size();
}

hash_table::~hash_table()
{
	delete[] array;
}
