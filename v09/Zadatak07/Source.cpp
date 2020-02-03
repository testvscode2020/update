#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include "Person.h"

using namespace std;



template <typename T>
T convert(string &s) 
{
	stringstream c(s);
	T t;
	c >> t;
	return t;
}

void load(ifstream &in, priority_queue<Person, vector<Person>, person_ibmcomparer_desc> &pq)
{
	string line;
	//skip header
	getline(in, line);
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		//skip column;
		string temp;
		getline(ss, temp, ',');
		string gender;
		getline(ss, gender, ',');
		getline(ss, temp, ',');
		int weight = convert<int>(temp);
		getline(ss, temp, ',');
		int height = convert<int>(temp);
		pq.emplace(gender, weight, height);
	}
}
int main()
{
	ifstream in("itm.csv");
	if (!in)
	{
		cout << "nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	priority_queue<Person, vector<Person>, person_ibmcomparer_desc> pq;
	load(in, pq);
	in.close();

	while (!pq.empty())
	{
		cout << pq.top().to_string() << endl;
		pq.pop();
	}

	return 0;
}