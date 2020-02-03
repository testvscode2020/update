#pragma once
class direct_addressing_table 
{
private:
	unsigned long long* array;
public:
	direct_addressing_table(unsigned n);
	void insert(int key, unsigned long long value);
	unsigned long long search(int key);
	~direct_addressing_table();
};