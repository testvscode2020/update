#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

/*
Generirajte vektor od razbacanih brojeva od 1 do 100. Sortirajte ga na tri 
načina te rezultate sortiranja zapišite u datoteke:
a)Rastuće
b)Padajuće
c)Tako da prvo dođu parni, a onda neparni brojevi 
(da, ovo bi trebalo raditi particioniranjem, ali idemo napraviti sortiranjem)
*/

void prepare_vector(vector<int> &v, unsigned n) 
{
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void write(ofstream &out, vector<int> &v) 
{
	for (int n : v)
	{
		out << n << endl;
	}
}

bool sort_desc(int a, int b) 
{
	return a > b;
}

bool sort_even_first(int a, int b) 
{
	return a % 2 == 0 && b % 2 == 1;
}

int main() 
{
	ofstream asc("rastuci.txt");
	ofstream desc("padajuci.txt");
	ofstream even_odd("parni_neparni.txt");
	if (!asc || !desc || !even_odd) 
	{
		cout << "Nije moguce kreirati datoteke" << endl;
		return 1;
	}

	srand(unsigned(time(nullptr)));
	vector<int> original;
	prepare_vector(original, 100);

	// a)
	vector<int> v(original);
	sort(v.begin(), v.end());
	write(asc, v);

	// b)
	v.assign(original.begin(), original.end());
	sort(v.begin(), v.end(), sort_desc);
	write(desc, v);

	// c)
	//v.assign(original.begin(), original.end());
	//sort(v.begin(), v.end(), sort_even_first);
	
	//primjer sa stable sortom - ostaviti sortirani vektor padajuce	
	stable_sort(v.begin(), v.end(), sort_even_first);
	write(even_odd, v);

	asc.close();
	desc.close();
	even_odd.close();

	return 0;
}