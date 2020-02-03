#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Napišite program koji sortira riječi iz datoteke osobe.txt 
na način da prvo dođu dulje, a onda kraće riječi. 
Riječi jednake duljine neka budu sortirane abecedno.
*/

void load(ifstream &in, vector<string> &v)
{
	string ime;
	while (getline(in, ime))
	{
		v.push_back(ime);
	}
}

void print(vector<string> &v)
{
	for (string s : v)
	{
		cout << s << endl;
	}
}

bool sort_by_length(string a, string b)
{
	return a.length() > b.length();
}

int main()
{
	ifstream in("osobe.txt");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<string> osobe;
	load(in, osobe);
	in.close();

	//prvo abecedno
	sort(osobe.begin(), osobe.end());
	//potom prema duljini
	stable_sort(osobe.begin(), osobe.end(), sort_by_length);

	print(osobe);

	return 0;
}