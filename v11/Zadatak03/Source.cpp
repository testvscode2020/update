#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

/*
Napišite program koji sortira riječi iz datoteke osobe.txt na 
način da prvo dođu kraće, a onda dulje riječi. Riječi jednake 
duljine ostavite u jednakom redoslijed u kakvom su u zadanoj datoteci. 
Rezultat mora biti sljedeći:
Ed
Mike
Erma
Kerry
Jamie
Gordon
Raquel
Ernesto
Winifred
Alexandra
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
	return a.length() < b.length();
}

int main() 
{	
	ifstream in("osobe.txt");
	if (!in) 
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return -1;
	}

	vector<string> v;
	load(in, v);
	in.close();

	stable_sort(v.begin(), v.end(), sort_by_length);

	print(v);

	return 0;
}