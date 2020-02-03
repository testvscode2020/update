#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int convert(string& s)
{
	stringstream c(s);
	int ip;
	c >> ip;
	return ip;
}


void read(ifstream& in, vector<int>& v)
{
	string line;
	while (getline(in, line))
	{
		//cout << line << endl;
		stringstream ss(line);
		string ip_s;
		getline(ss, ip_s, '.');
		int ip = convert(ip_s);

		//cout << ip << endl;
		v.push_back(ip);
	}
}


int main()
{
	string filename = "ip_adrese.txt";
	ifstream in(filename);
	if (!in)
	{
		cout << "no can do" << endl;
		return 1;
	}
	vector<int> v;
	read(in, v);
	in.close();
	
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		int ip = *it;
		if (ip > 1 && ip < 127)
		{
			a++;
		}
		else if (ip > 126 && ip < 192)
		{
			b++;
		}
	}

	cout << "Klasa a"
	for (int i = 0; i < a; i++)
	{
		cout << "#";
	}
	cout << "(" << a << ")" << endl;

	return 0;
}
