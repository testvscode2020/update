#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void prepare_vector(vector<int> &v)
{
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void write(ofstream &output, vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		output << v[i] << endl;
	}
}

bool sort_desc(int a, int b) 
{
	return a > b;
}

bool parni(int a)
{
	return a % 2 == 0;
}

int main()
{
	ofstream output_rastuci("rastuci.txt");
	ofstream output_padajuci("padajuci.txt");
	ofstream output_pn("pn.txt");

	srand(time(nullptr));
	vector<int> originalni;
	prepare_vector(originalni);

	vector<int>v(originalni);
	sort(v.begin(), v.end());
	write(output_rastuci, v);

	v.assign(originalni.begin(), originalni.end());

	sort(v.begin(), v.end(), sort_desc);
	write(output_padajuci, v);

	v.assign(originalni.begin(), originalni.end());

	partition(v.begin(), v.end(), parni);
	write(output_pn, v);
}