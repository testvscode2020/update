#pragma once

#include <list>
using namespace std;

struct entry
{
	int key;
	unsigned long long value;
	entry(int key, unsigned long long value)
	{
		this->key = key;
		this->value = value;
	}
};

class hash_table
{
private:
	const int M = 100003;
	list<entry>* array;
	int h(int key);
public:
	hash_table();
	void insert(int key, unsigned long long value);
	unsigned long long search(int key);
	int get_buckets();
	int get_elements_in_bucket(int n);
	~hash_table();
};