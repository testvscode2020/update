#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

/*
Generirajte vektor od razbacanih brojeva od 1 do 100. Sortirajte ga na sljedeća tri načina te rezultate svakog sortiranja zapišite u posebnu datoteku (pokretanjem programa trebaju nastati tri datoteke):
a. Rastuće
b. Padajuće
c. Tako da prvo dođu parni, a onda neparni brojevi.
*/

void prepare_vector(vector<int> &v)
{
	for (int i = 1; i <= 100; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
}

void write(ofstream &out, vector<int> v)
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

bool even(int a)
{
	return a % 2 == 0;
}


int main()
{
	ofstream out1("rastuci.txt");
	ofstream out2("padajuci.txt");
	ofstream out3("parni_neparni.txt");
	if (!out1 || !out2 || !out3)
	{
		cout << "Nije moguce kreirati datoteke" << endl;
		return 1;
	}

	srand(unsigned(time(nullptr)));
	vector<int> original;
	prepare_vector(original);

	// a)
	vector<int> v(original);
	sort(v.begin(), v.end());
	write(out1, v);

	// b)
	v.assign(original.begin(), original.end());
	sort(v.begin(), v.end(), sort_desc);
	write(out2, v);

	// c)
	//vector<int>::iterator part = partition(v.begin(), v.end(), even);
	auto part = partition(v.begin(), v.end(), even);
	//1. nacin - do partitiona i poslije njega
	//for (auto it = v.begin(); it != part; it++)
	//{
	//	out3<< *it << endl;
	//}
	//for (auto it = part; it != v.end(); it++)
	//{
	//	out3 << *it << endl;
	//}
	//2.nacin - odmah sve
	write(out3, v);


	out1.close();
	out2.close();
	out3.close();

	return 0;
}