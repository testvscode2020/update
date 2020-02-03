#pragma once
#include <string>

using namespace std;

struct message
{
	string text;
	int priority;
	message(string text, int priority) {
		this->text = text;
		this->priority = priority;
	}
};

struct message_comparer_desc
{
	bool operator() (const message &m1, const message &m2) const
	{
		return m1.priority < m2.priority;
	}
};
