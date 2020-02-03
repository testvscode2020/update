#pragma once
class hash_table 
{
private:
	const int M = 100003;
	unsigned long long* array;
	int h(int key);
	int nr_conflicts = 0;
public:
	hash_table();
	void insert(int key, unsigned long long value);
	unsigned long long search(int key);
	int get_nr_conflicts();
	~hash_table();
};