#pragma once

class MojVektorNum {
private:
	int values[100];
	unsigned next = 0;
public:
	class iterator {
	private:
		int* ptr;

	public:
		iterator(int* ptr);
		int& operator*();
		iterator& operator++();
		bool operator==(const iterator& rhs);
		bool operator!=(const iterator& rhs);
	};

	void push_back(int val);
	iterator begin();
	iterator end();
};