//moram ucitat brojee u listu iz ulazne datoteke . 
//onda moramo izbrisati sve iz liste djeljiv sa dva
//onda
#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void fill(ifstream& in, list<int>& l)
{
	int i;
	//in >> i; //ovo vraca true ili false
	while (in >> i)
	{
		l.push_back(i); //da pratimo redosljed ide pushback. pushfront ide u riki
	}
}

void delete_steven(list<int>& l)
{
	//iterator prolazi kroz sve kolekcije, zato je iterator patern(to je vanjski) igrac. neovisno o kolekciji uvjek na isti nacin prolazi kroz nju
	for (auto it = l.begin(); it != l.end(); ) // ovo je najispravnija forpetlja za iteratore
	{
		//cout << *it << endl; //iterator je pokazivac, zato ga moramo dereferencirati. 
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
}

bool steven(int& i)
{
	return i % 2 == 0;
}

void multiply(list<int>& l)
{
	for (auto it = l.begin(); it != l.end(); ++it) // ovo je najispravnija forpetlja za iteratore
	{
		*it *= 3;
	}
}

void multiply(vector<int>& l)
{
	for (auto it = l.begin(); it != l.end(); ++it) // ovo je najispravnija forpetlja za iteratore
	{
		*it *= 3;
	}
}

void copy(list<int>& l, vector<int>& v)
{
	for (auto it = l.rbegin(); it != l.rend(); ++it) // ovo je najispravnija forpetlja za iteratore
	{
		v.push_back(*it);
	}
}

void copy(vector<int>& v, stack<int>& s)
{
	for (auto it = v.begin(); it != v.end(); ++it) // ovo je najispravnija forpetlja za iteratore
	{
		s.push(*it);
	}
}



void print(stack<int>& s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}


int main()
{
	ifstream in("brojevi.txt");
	if (!in)
	{
		cout << "no can do";
		return 1;
	}

	list<int> l;

	fill(in, l);

	in.close();

	//delete_steven(l); //to je kao delete even. 
	l.remove_if(steven);
	multiply(l);

	vector<int> v;
	copy(l, v);

	multiply(v);

	stack<int> s;

	copy(v, s);

	print(s);

	return 0;
}