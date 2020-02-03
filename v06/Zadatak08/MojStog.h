#pragma once
class MojStog
{
public:
	void push(int val);
	bool empty();
	int top();
	void pop();
private:
	int values[10];
	unsigned vrh = 0;
};