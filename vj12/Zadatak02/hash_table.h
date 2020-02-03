#pragma once
class hash_table 
{
private:
	unsigned long long* array;
	int h(int key);
public:
	hash_table(unsigned n);
	void insert(int key, unsigned long long value);
	unsigned long long search(int key);
	~hash_table();
};