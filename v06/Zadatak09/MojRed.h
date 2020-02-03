#pragma once
class MojRed
{
public:
	void push(int val);
	bool empty();
	int front();
	void pop();
private:
	int values[10];
	unsigned vrh = 0;
};

