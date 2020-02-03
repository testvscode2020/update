/*
generirajte vektor od razbacanih brojeva od 100 do 200. sortirajte ga na sljedeci tri nacina 
rastuce
padajuce
tako da do prvo doðu brojevi veci od 150, a onda ostali(koristeci STL particioniranje

rezultate svakog sortiranja zapisite u posebnu datoteku(pokretanjem programa trebaju nastati tri datoteka
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

void fill(vector<int>& v, int min, int max)
{
	for (int i = min; i < max; i++)
	{
		v.push_back(i);
	}
}

void save(ofstream& out, vector<int>& v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		//out << *it << " ";
		out << *it << endl; 
	}
	out << endl; // jeftino debugiranje
}

bool desc(int& a, int& b)
{
	return a > b; //<.... rastuce
}

bool veceOd150(int a)
{
	return a > 150; //<.... rastuce
}


int main()
{
	ofstream out1("rastuce.txt");
	ofstream out2("padajuce.txt");
	ofstream out3("particionirane.txt");
	if (!out1 || !out2 || !out3)
	{
		cout << "404" << endl;
		return 1;
	}

	vector<int> v;
	fill(v, 100, 200);

	random_shuffle(v.begin(), v.end());

	partition(v.begin(), v.end(), veceOd150); //prvo radimo ovo jer ako to ostavimo kasnije onda je vec vector sortiran
	save(out3, v);

	sort(v.begin(), v.end()); //ascending - rastuce
	save(out1, v);

	sort(v.begin(), v.end(), desc); 
	save(out2, v);

	//partition(v.begin(), v.end(), veceOd150); //prebacili smo to prema gore. 
	//save(out3, v);


	//cout << "hi mom" << endl;

	out1.close();
	out2.close();
	out3.close();


	return 0;
}